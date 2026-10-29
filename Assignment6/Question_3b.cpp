#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;

    public:
        DoublyLinkedList() : head(nullptr) {}
        ~DoublyLinkedList() {
            Node* curr = head;
            while(curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            head = nullptr;
        }

        void insert(int data) {
            Node* newNode = new Node(data);

            if(head==nullptr) {
                head = newNode;
                return;
            }
            Node* curr = head;
            while(curr->next != nullptr) {
                curr=curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }

        int sizeofLL() {
            if(head==nullptr) return 0;
            Node* curr = head;
            int c=1;
            while(curr->next != nullptr) {
                curr = curr->next;
                c++;
            }
            return c;
        }
};
int main() {
    DoublyLinkedList cl;
    int option;
    do {
        int x;
        cout << "Enter data for node: ";
        cin >> x;
        cl.insert(x);
        cout << "Enter 0 to stop or any number to continue!" << endl;
        cin >> option;
    } while(option != 0);

    cout << endl << "Size of the Doubly LinkedList is: " << cl.sizeofLL();
    return 0;
}