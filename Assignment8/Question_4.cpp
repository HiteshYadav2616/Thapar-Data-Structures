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

void inorder(Node* root) {
    if(root==nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void insert(Node*& root, int val) {
    if(root==nullptr) {
        root=new Node(val);
        return;
    }
    if(root->data>val) insert(root->left, val);
    else if(root->data<val) insert(root->right, val);
}

bool helper1(Node* root, int min, int max) {
    if(root==nullptr) return true;
    if(root->data<=min || root->data>=max) return false;
    return helper1(root->left, min, root->data) && helper1(root->right, root->data, max);
}

bool isBST(Node* root) {
    int min = INT_MIN;
    int max = INT_MAX;
    return helper1(root, min, max);
}
int main() {
    Node* root = nullptr;
    int n;
    cout << "How many nodes you want to enter:";
    cin >> n;

    cout << "\nEnter the values:" << endl;
    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        insert(root, data);
    }

    cout << "Inorder traversal of BST:" << endl;
    inorder(root);

    cout << endl;
    if(isBST(root)) {
        cout << "Valid BST" << endl;
    } else {
        cout << "Invalid BST" << endl;
    }

    return 0;
}