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
        int findOccurences(int x) {
            int count = 0;
            while(head!=nullptr && head->data==x) {
                count++;
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            Node* curr = head;
            while(curr != nullptr && curr->next!=nullptr) {
                if(curr->next->data==x) {
                    count++;
                    Node* temp = curr->next;
                    curr->next = temp->next;
                    delete temp;
                } else {
                curr = curr->next;
                }
            }
            return count;
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
    int n;
    cout << "Enter how many nodes you want to insert: ";
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cout << "\nEnter data of node " << i+1 << " : ";
        cin >> x;
        l.insertAtEnd(x);
    }
    l.show();
    int y;
    cout << endl << "Enter element to find occurences: ";
    cin >> y;
    cout << y << " occurs (" << l.findOccurences(y) << ") in the list" << endl;
    l.show();
    return 0;
}