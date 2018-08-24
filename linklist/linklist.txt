#include <iostream>
using namespace std;


struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};


class LinkList {
private:

public:
    Node* reverseInsert(Node* head) {
        if (!head) {
            return head;
        } 
        if (!head->next) {
            return head;
        }
        Node* last2Node = head->next;
        Node* insertPos = head->next;
        Node* insertNode = insertPos->next;
        while (insertNode) {
            // cout<<insertNode->val<<',';
            head->next = insertNode;
            insertNode = insertNode->next;
            head->next->next = insertPos;
            insertPos = head->next;
        }
        last2Node->next = head;
        head->next = NULL;
        return insertPos;
    }


    Node* reverse3P(Node* head) {
        if (!head) {
            return head;
        } 
        if (!head->next) {
            return head;
        }
        Node* pre = NULL;
        Node* cur = head;
        Node* next = head->next;
        while (cur) {
            cur->next = pre;
            pre = cur;
            cur = next;
            if (next) {
                next = next->next;
            }
        }
        return pre;
    }

};

int main() {
    LinkList myLinkList;
    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    Node *node = head;
    while (node) {
        cout<<node->val<<',';
        node = node->next;
    }
    cout<<endl;
    // Node * res = myLinkList.reverseInsert(head);
    Node * res = myLinkList.reverse3P(head);
    node = res;
    while (node) {
        cout<<node->val<<',';
        node = node->next;
    }
    cout<<endl;
    return 1;
}
