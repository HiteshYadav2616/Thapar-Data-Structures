#include<iostream>
#include<cstddef>
#define MAX 1000
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

int getHash(Node* node) {
    return (size_t)node % MAX;
}

class LinkedList {
    Node* head;
    public:
        LinkedList() : head(nullptr) {}

        void insert(int x) {
            Node* newNode = new Node(x);
            if(head==nullptr) {
                head=newNode;
                newNode->next = head;
                return;
            }
            Node* curr = head;
            while(curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
        }

        bool isCycle() {
            Node* hash_set[MAX] = {nullptr};
            Node* curr = head;
            if(head==nullptr) return false;

            while(curr != nullptr) {
                int idx = getHash(curr);
                while(hash_set[idx] != nullptr) {
                    if(hash_set[idx]==curr) return true;
                    idx = (idx+1)%MAX;
                }
                hash_set[idx]=curr;
                curr = curr->next;
            }
            return false;
        }
};

int main() {
    LinkedList l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);

    if(l.isCycle()) {
        cout << "Cycle exists";
    } else
    cout << "Cycle doesn't exists";

    return 0;
}