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

void inorder(Node* root) {
    if(root==nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* deleteNode(Node* root, int key) {
    if(root==nullptr) return nullptr;
    if(root->data>key) {
        root->left = deleteNode(root->left, key);
    } else if(root->data<key) {
        root->right = deleteNode(root->right, key);
    } else {
        if(root->left==nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* curr = root->right;
            while(curr->left!=nullptr) {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if(root==nullptr) return -1;
    return 1+max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if(root==nullptr) return -1;
    return 1+min(minDepth(root->left), minDepth(root->right));
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

    int option;
    cout << "\n1. Delete existing Node\n2. Minimum Depth pf Tree\n3. Maximum Depth of Tree\n>>Option: ";
    cin >> option;

    switch(option) {
        case 1: {
            int x;
            cout << "Enter value of node to delete: ";
            cin >> x;
            deleteNode(root, x);
            cout << "Inorder traversal of BST:" << endl;
            inorder(root);
            break;
        }
        case 2: {
            cout << "\nMinimum Depth of Tree: " << minDepth(root);
            break;
        }
        case 3: {
            cout << "\nMaximum Depth of Tree: " << maxDepth(root);
            break;
        }
        default: {
            cout << "Choose a valid option!";
        }
    }
    return 0;
}