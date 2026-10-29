#include<iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;

    Node(char data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {}
        ~DoublyLinkedList() {
            Node* curr = head;
            while(curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            head = tail = nullptr;
        }

        void insert(char data) {
            Node* newNode = new Node(data);

            if(head==nullptr) {
                head = newNode;
                tail = head;
                return;
            }
            Node* curr = head;
            while(curr->next != nullptr) {
                curr=curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
            tail = newNode;
        }
        bool checkPalindrome() {
            if(head==nullptr || head->next==nullptr) return true;
            Node* f = head;
            Node* b = tail;
            while(f!=nullptr && b!=nullptr && f->next != b->prev && f->next != b) {
                if(f->data != b->data) return false;
                f=f->next;
                b=b->prev;
            }
            return true;
        }

        void display() {
            if(head==nullptr) return;
            Node* curr = head;
            while(curr != nullptr) {
                cout << curr->data << " ";
                curr = curr->next;
            }
        }
};

int main() {
    DoublyLinkedList dl;
    int x;
    cout << "Number of nodes you want to insert: ";
    cin >> x;

    for(int i=0; i<x; i++) {
        char y;
        cout << "Enter data of Node " << (i+1) << " : ";
        cin >> y;
        dl.insert(y); 
    }
    cout << endl;
    cout << "Doubly LinkedList:" << endl;
    dl.display();

    if(dl.checkPalindrome()) {
        cout << "\nYes it is a Palindromic Doubly LinkedList";
    } else {
        cout << "\nNo it is not a palindrome";
    }
    return 0;
}