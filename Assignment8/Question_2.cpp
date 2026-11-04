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

bool search(Node* root, int key) {
    if(root==nullptr) return false;
    if(root->data==key) return true;
    if(key<root->data) return search(root->left, key);
    else return search(root->right, key);
}

void inorder(Node* root) {
    if(root==nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int maxElement(Node* root) {
    if(root == nullptr) return -1;
    Node* curr = root; 
    while(curr->right!=nullptr) {
        curr=curr->right;
    }
    return curr->data;
}

int minElement(Node* root) {
    if(root == nullptr) return -1;
    Node* curr = root; 
    while(curr->left!=nullptr) {
        curr=curr->left;
    }
    return curr->data;
}

int inorderSuccessor(Node* root, int key) {
    Node* curr = root;
    Node* succ = nullptr;

    while(curr!=nullptr) {
        if(key<curr->data) {
            succ = curr;
            curr = curr->left;
        } else if(key>curr->data) {
            curr = curr->right;
        } else {
            curr = curr->right;
            while(curr!=nullptr) {
                succ = curr;
                curr = curr->left;
            }
            break;
        }
    }
    if(succ == nullptr) {
        cout << "No successor exists (it is the maximum element). ";
        return -1;
    }
    return succ->data;
}

int inorderPredecessor(Node* root, int key) {
    Node* curr = root;
    Node* pred = nullptr;

    while(curr!=nullptr) {
        if(key<curr->data) {
            curr = curr->left;
        } else if(key>curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
            while(curr!=nullptr) {
                pred = curr;
                curr = curr->right;
            }
            break;
        }
    }
    if(pred == nullptr) {
        cout << "No predecessor exists (it is the minimum element). ";
        return -1;
    }
    return pred->data;
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
    cout << "\n\n1. Search an element\n2. Min of BST\n3. Max of BST\n4. Inorder Successor of a node\n5. Inorder Predecessor of a node\nChoose option: ";
    cin >> option;

    switch(option) {
        case 1: {
            int x;
            cout << "\nEnter element you want to search: ";
            cin >> x;

            if(search(root, x)) {
                cout << "Element found!";
            } else {
                cout << "Element not found!";
            }
            break;
        }
        case 2: {
            cout << "Minimum element of BST is: " << minElement(root) << endl;
            break;
        }
        case 3: {
            cout << "Maximum element of BST is: " << maxElement(root) << endl;
            break;
        }
        case 4: {
            int x;
            cout << "Enter data of the node: ";
            cin >> x;
            cout << "Inorder Successor: " << inorderSuccessor(root, x);
            break;
        }
        case 5: {
            int x;
            cout << "Enter data of the node: ";
            cin >> x;
            cout << "Inorder Predecessor: " << inorderPredecessor(root, x);
            break;
        }
        default: {
            cout << "Choose a valid option!" << endl;
        }
    }

    return 0;
}