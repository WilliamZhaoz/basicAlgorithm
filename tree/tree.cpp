#include <iostream>
#include <stack>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Tree {
public:
    void recursiveInorderTraversal(TreeNode *root) {
        if (root != NULL) {
            recursiveInorderTraversal(root->left);
            cout<<root->val<<",";
            recursiveInorderTraversal(root->right); 
        }
    }

    void nonRecursiveInorderTraversal(TreeNode *root) {
        stack<TreeNode*> mystack;
        TreeNode *node = root; 
        while (node != NULL || !mystack.empty()) {
            if (node != NULL) {
                mystack.push(node);
                node = node->left;
            } else {
                cout<<mystack.top()->val<<",";
                node = mystack.top()->right;
                mystack.pop();
            }
        }
    }

    void recursivePreorderTraversal(TreeNode *root) {
        if (root != NULL) {
            cout<<root->val<<",";
            recursivePreorderTraversal(root->left);
            recursivePreorderTraversal(root->right);
        }
    }

    void nonRecursivePreorderTraversal(TreeNode *root) {
        stack<TreeNode*> mystack;
        TreeNode *node = root;
        while (node != NULL || !mystack.empty()) {
            if (node != NULL) {
                cout<<node->val<<",";
                mystack.push(node);
                node = node->left;
            } else {
                node = mystack.top()->right;
                mystack.pop();
            }
        }
    }
    
    void nonRecursivePreorderTraversal_(TreeNode *root) {
        stack<TreeNode*> mystack;
        mystack.push(root);
        while (!mystack.empty()) {
            TreeNode *node = mystack.top();
            cout<<mystack.top()->val<<",";
            mystack.pop();
            if (node->right != NULL) {
                mystack.push(node->right);
            }
            if (node->left != NULL) {
                mystack.push(node->left);
            }
        }
    }

    void recursivePostorderTraversal(TreeNode *root) {
        if (root != NULL) {
            recursivePostorderTraversal(root->left);
            recursivePostorderTraversal(root->right);
            cout<<root->val<<",";
        }
    }

    void nonRecursivePostorderTraversal(TreeNode *root) {
        stack<TreeNode*> mystack;
        TreeNode *cur;
        TreeNode *pre = NULL;
        mystack.push(root);
        while (!mystack.empty()) {
            cur = mystack.top();
            if ((cur->left == NULL && cur->right == NULL) ||
                    (pre != NULL && (pre == cur->left || pre == cur->right))) {
                cout<<cur->val<<",";
                mystack.pop();
                pre = cur;
            } else {
                if (cur->right != NULL) {
                    mystack.push(cur->right);
                if (cur->left != NULL) {
                    mystack.push(cur->left);
                }
                }
            } 
        }
    }

    void levelTraversal(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        while (!myqueue.empty()) {
            cout<<myqueue.front()->val<<",";
            if (myqueue.front()->left != NULL) {
                myqueue.push(myqueue.front()->left);
            }
            if (myqueue.front()->right != NULL) {
                myqueue.push(myqueue.front()->right);
            }
            myqueue.pop();
        }


    }
};

// reference: https://www.cnblogs.com/jdneo/p/5394489.html


int main() {
    Tree myTree;
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    myTree.recursiveInorderTraversal(root);
    cout<<endl;
    myTree.nonRecursiveInorderTraversal(root);
    cout<<endl;
    myTree.recursivePreorderTraversal(root);
    cout<<endl;
    myTree.nonRecursivePreorderTraversal(root);
    cout<<endl;
    myTree.nonRecursivePreorderTraversal_(root);
    cout<<endl;
    myTree.recursivePostorderTraversal(root);
    cout<<endl;
    myTree.nonRecursivePostorderTraversal(root);
    cout<<endl;
    myTree.levelTraversal(root);
    cout<<endl;
