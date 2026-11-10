#include<iostream>
#define MAX 1000
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

bool traversal(Node* root, int hash_set[]) {
    if(root==nullptr) return false;
    if(hash_set[root->data]==1) return true;
    hash_set[root->data] = 1;
    return traversal(root->left, hash_set) || traversal(root->right, hash_set);
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(7);

    int hash_set[MAX] = {0};

    if(traversal(root, hash_set)) cout << "Duplicates exists!";
    else cout << "No duplicates exists";
    return 0;
}