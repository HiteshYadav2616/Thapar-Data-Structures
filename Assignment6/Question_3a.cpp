#include<iostream>
using namespace std;

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
        int sizeofLL() {
            if(head==nullptr) return 0;
            Node* curr = head;
            int c=1;
            while(curr->next != head) {
                curr = curr->next;
                c++;
            }
            return c;
        }
};
int main() {
    CircularLinkedList cl;
    int option;
    do {
        int x;
        cout << "Enter data for node: ";
        cin >> x;
        cl.insert(x);
        cout << "Enter 0 to stop or any number to continue!" << endl;
        cin >> option;
    } while(option != 0);

    cout << endl << "Size of the Circular LinkedList is: " << cl.sizeofLL();
    return 0;
}