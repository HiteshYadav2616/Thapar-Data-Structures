#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node*& root, int val) {
    Node* newNode = new Node(val);
    if(root==nullptr) {
        root=newNode;
        return;
    }
    if(root->data>val) insert(root->left, val);
    else if(root->data<val) insert(root->right, val);
}

bool isBST(Node* root) {
    return root->data>isBST(root->left) && root->data<isBST(root->right);
}
int main() {
    return 0;
}