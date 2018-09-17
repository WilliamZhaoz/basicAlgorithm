// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class UnionFind {
private:
	unordered_map<int, int> fatherMap;
	int count;
public:
	int find_(int x) {
		int father = fatherMap[x];
		while (father != fatherMap[father]) {
			father = fatherMap[father];
		}
		return father;
	}
	void union_(int x, int y) {
		int x_root = find_(x), y_root = find_(y);
		if (x_root != y_root) {
			count--;
			fatherMap[x_root] = y_root;
		}
	}
	int find_compressed(int x) {
		int father = fatherMap[x];
		while (father != fatherMap[father]) {
			father = fatherMap[father];
		}
		int next;
		while (x != fatherMap[x]) {
			next = fatherMap[x];
			fatherMap[x] = father;
			x = next;
		}
		return father;

	}
	void set_count(int c) {
		count = c;
	}
	int get_count() {
		return count;
	}
	UnionFind(){};
	UnionFind(int c, int n) {
		count = c;
		for (int i = 0; i < n; i++) {
			fatherMap[i] = i;
		}
	};
};


int main()
{
	// num of ilands
	vector<vector<char>> grid{ { '1', '1', '0', '0', '0' }, { '1', '1', '0', '0', '0' }, {'0', '0', '1', '0', '0' }, { '0', '0', '0', '1', '1' } };

	if (grid.empty() || grid[0].empty()) {
		return 0;
	}
	int m = grid.size(), n = grid[0].size(), res = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '1') {
				res++;
			}
		}
	}
	UnionFind uf(res, m * n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '1') {
				if (i + 1 < m && grid[i + 1][j] == '1') {
					uf.union_(i * n + j, (i + 1) * n + j);
				}
				if (j + 1 < n && grid[i][j + 1] == '1') {
					uf.union_(i * n + j, i * n + j + 1);
				}
				if (i - 1 >= 0 && grid[i - 1][j] == '1') {
					uf.union_(i * n + j, (i - 1) * n + j);
				}
				if (j - 1 >= 0 && grid[i][j - 1] == '1') {
					uf.union_(i * n + j, i * n + j - 1);
				}
			}
		}
	}
	cout << uf.get_count();
	return 0;
}

