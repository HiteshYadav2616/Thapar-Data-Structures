#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    Node* head;

    public:
        LinkedList() : head(nullptr) {}
        ~LinkedList() {
            Node* curr = head;
            while(curr != nullptr) {
                Node* temp = curr->next;
                delete curr;
                curr = temp;
            }
        }
        void insertAtEnd(int data) {
            Node* newNode = new Node(data);
            if(head==nullptr) {
                head = newNode;
                return;
            }
            Node* curr = head;
            while(curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        void reverse() {
            if(head==nullptr || head->next==nullptr) {
                return;
            }
            Node* prev = nullptr;
            Node* curr = head;
            while(curr!=nullptr) {
                Node* nextNode = curr->next;
                curr->next = prev;

                prev = curr;
                curr = nextNode;
            }
            head = prev;
        }
        void show() {
            Node* curr = head;
            while(curr!=nullptr) {
                cout << curr->data << " ";
                curr = curr->next;
            }
        }
};
int main() {
    LinkedList l;

    l.insertAtEnd(10);
    l.insertAtEnd(20);
    l.insertAtEnd(30);
    l.insertAtEnd(40);
    l.insertAtEnd(50);
    l.insertAtEnd(60);
    l.insertAtEnd(70);
    l.insertAtEnd(80);
    cout << "Original LL:" << endl;
    l.show();
    cout << "\nAfter reversing:" << endl;
    l.reverse();
    l.show();
    return 0;
}