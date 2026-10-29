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

class CircularLinkedList {
    Node* head;

    public:
        CircularLinkedList() : head(nullptr) {}
        ~CircularLinkedList() {
            Node* curr = head->next;
            while(curr != head) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            delete head;
            head = nullptr;
        }

        void insert(int data) {
            Node* newNode = new Node(data);

            if(head==nullptr) {
                head = newNode;
                newNode->next = head;
                return;
            }
            Node* curr = head;
            while(curr->next != head) {
                curr=curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
        }

        void display() {
            if(head == nullptr) return;
            Node* curr = head;
            while(curr->next!=head) {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << curr->data << " " << curr->next->data;
        }
};

int main() {
    CircularLinkedList cl;
    int x;
    cout << "Number of nodes you want to insert: ";
    cin >> x;

    for(int i=0; i<x; i++) {
        int y;
        cout << "Enter data of Node " << (i+1) << " : ";
        cin >> y;
        cl.insert(y); 
    }
    cout << endl;
    cout << "Circular LinkedList:" << endl;
    cl.display();
    return 0;
}