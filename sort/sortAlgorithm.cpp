#include <iostream>
#include <vector>
using namespace std;

class Sort {
public:

    void bubbleSort(vector<int> &vec) {
        if (vec.empty()) return;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = vec.size() - 1; j > i; j--) {
                if (vec[j] < vec[j - 1]) {
                    vec[j] ^= vec[j - 1];
                    vec[j - 1] ^= vec[j];
                    vec[j] ^= vec[j - 1];
                }
            }
        }
        return; 
    }

    void selectSort(vector<int> &vec) {
        if (vec.empty()) return;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec[j] < vec[i]) {
                    vec[i] ^= vec[j];
                    vec[j] ^= vec[i];
                    vec[i] ^= vec[j];
                }
            }
        }
        return;
    }


    void insertSort(vector<int> &vec) {
        if (vec.empty()) return;
        for (int i = 0; i < vec.size(); i++) {
            int j = i;
            while (j > 0 && vec[i] < vec[j - 1]) j--;
            vec.insert(vec.begin() + j, vec[i]);
            vec.erase(vec.begin() + i + 1);
        }
    }


    void quickSort(vector<int> &vec) {
        if (vec.empty()) return;
        quickSort_(vec, 0, vec.size() - 1);
    }
    void quickSort_(vector<int> &vec, int left, int right) {
        if(left >= right) return;
        int pivotPos = partition(vec, left, right);
        quickSort_(vec, left, pivotPos - 1);
        quickSort_(vec, pivotPos + 1, right);
    }
    int partition(vector<int> &vec, int left, int right) {
        int pivotKey = vec[left];
        while (left < right) {
            while(left < right && vec[right] >= pivotKey) right--;
            vec[left] = vec[right];
            while(left < right && vec[left] <= pivotKey) left++;
            vec[right] = vec[left];
        }
        vec[left] = pivotKey;
        return left;
    }


    void heapSort(vector<int> &vec) {
        int len = vec.size();
        for (int root = len / 2 - 1; root >= 0; root--) {
            buildHeap(vec, root, len);
        }    
        for (int j = len - 1; j > 0; j--) {
            swap(vec[0], vec[j]);
            buildHeap(vec, 0, j);
        }
    }
    void buildHeap(vector<int> &vec, int root, int len) {
        int lc = root * 2 + 1;
        if (lc >= len) {
            return;
        }
        int flag = lc;
        int rc = lc + 1;
        if (rc < len) {
            flag = vec[rc] > vec[lc] ? rc : lc;
        }
        if (vec[root] < vec[flag]) {
            swap(vec[root], vec[flag]);
            buildHeap(vec, flag, len);
        }
    }
    void swap(int &a, int &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }


    void mergeSort(vector<int> &vec) {
        mergeSort_(vec, 0, vec.size() - 1);
    }
    void mergeSort_(vector<int> &vec, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort_(vec, left, mid);
        mergeSort_(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
    void merge(vector<int> &vec, int left, int mid, int right) {
        vector<int> l(vec.begin() + left, vec.begin() + mid + 1);
        vector<int> r(vec.begin() + mid + 1, vec.begin() + right + 1);
        int i = 0, j = 0;
        while (i < l.size() && j < r.size()) {
            if (l[i] <= r[j]) {
                vec[left++] = l[i++];
            } else {
                vec[left++] = r[j++];
            }
        }
        while (i < l.size()) {
            vec[left++] = l[i++];
        }
        while (j < r.size()) {
            vec[left++] = r[j++];
        }
    }

};



int main() {
    Sort sorter;
    int arr[] = {7, 2, 1, 9, 8, 5};
    vector<int> vec(arr, arr + 6);
    // sorter.bubbleSort(vec);
    // sorter.selectSort(vec);
    // sorter.quickSort(vec);
    // sorter.insertSort(vec);
    // sorter.heapSort(vec);
    sorter.mergeSort(vec);
    for_each(vec.begin(), vec.end(), [](const int& val)->void{cout<<val<<endl;});
    return 1;
}
