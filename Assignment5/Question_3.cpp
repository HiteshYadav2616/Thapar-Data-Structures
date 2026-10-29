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
        Node* findMiddle() {
            if(head==nullptr || head->next==nullptr) {
                return head;
            }
            Node* slow = head;
            Node* fast = head;
            while(fast!=nullptr && fast->next!=nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
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
    l.show();
    Node* temp = l.findMiddle();
    cout << endl;
    if(temp!=nullptr) {
        cout << "Middle of the LinkedList: " << temp->data << endl;
    } else {
        cout << "LinkedList is empty" << endl;
    }
    return 0;
}