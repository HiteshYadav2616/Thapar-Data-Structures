#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node* head;

    public:
        CircularLinkedList() : head(nullptr) {}
        ~CircularLinkedList() {
            Node* curr = head->next;

            while(curr!=head) {
                Node* temp = curr->next;
                delete curr;
                curr = temp;
            }
            delete head;
            head=nullptr;
        }

        void insertAtBegin(int data) {
            Node* newNode = new Node(data);
            if(head==nullptr) {
                head = newNode;
                newNode->next = head;
                return;
            }
            Node* curr = head;
            while(curr->next!=head) {
                curr = curr->next;
            }
            newNode->next = head;
            curr->next = newNode;
            head = newNode;
        }

        void insertAtEnd(int data) {
            Node* newNode = new Node(data);
            if(head==nullptr) {
                head = newNode;
                newNode->next = head;
                return;
            }
            Node* curr = head;
            while(curr->next!=head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
        }

        void insertBefore(int data, int x) {
            if(head->data==x) {
                insertAtBegin(data);
                return;
            }
            Node* newNode = new Node(data);
            Node* curr = head;
            while(curr->next!=head && curr->next->data!=x) {
                curr = curr->next;
            }
            if(curr->next!=head) {
                newNode->next = curr->next;
                curr->next = newNode;
            } else {
                cout << "Failed to insert" << endl;
                delete newNode;
            }
        }

        void insertAfter(int data, int x) {
            Node* newNode = new Node(data);
            if(head->data==x) {
                newNode->next = head->next;
                head->next = newNode;
                return;
            }
            Node* curr = head->next;
            while(curr!=head && curr->data!=x) {
                curr = curr->next;
            }
            if(curr!=head) {
                newNode->next = curr->next;
                curr->next = newNode;
            } else {
                cout << "Failed to insert" << endl;
                delete newNode;
            }
        }
        void deleteAtBegin() {
            if(head==nullptr) return;

            Node* curr = head;
            while(curr->next!=head) {
                curr = curr->next;
            }
            Node* temp = head;
            head = head->next;
            curr->next = head;
            delete temp;
        }
        void deleteAtSpecific(int x) {
            if(head->data==x) {
                deleteAtBegin();
                return;
            }
            Node* curr = head;
            while(curr->next!=head && curr->next->data!=x) {
                curr = curr->next;
            }
            if(curr->next!=head) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
        }

        int search(int x) {
            if(head==nullptr) return -1;
            if(head->data==x) return 1;
            int count = 2;
            Node* curr = head->next;
            while(curr!=head && curr->data!=x) {
                curr=curr->next;
                count++;
            }
            if(curr!=head) {
                return count;
            }
            return -1;
        }
};

int main() {
    CircularLinkedList l;
    int option, data, x;

    do {
        cout << "\n1. Insert at Begin" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert Before a specific Node" << endl;
        cout << "4. Insert After a specifc Node" << endl;
        cout << "5. Delete a specific Node" << endl;
        cout << "6. Search for a Node" << endl;
        cout << "7. Exit" << endl;
        cin >> option;

        switch(option) {
            case 1: {
                cout << "Enter data for the Node: ";
                cin >> data;
                l.insertAtBegin(data);
                break;
            }
            case 2: {
                cout << "Enter data for the Node: ";
                cin >> data;
                l.insertAtEnd(data);
                break;
            }
            case 3: {
                cout << "Enter data for the Node: ";
                cin >> data;
                cout << "Enter Before which Node:";
                cin >> x;

                l.insertBefore(data, x);
                break;
            }
            case 4: {
                cout << "Enter data for the Node: ";
                cin >> data;
                cout << "Enter After which Node:";
                cin >> x;

                l.insertAfter(data, x);
                break;
            }
            case 5: {
                cout << "Enter which Node to delete: ";
                cin >> x;
                l.deleteAtSpecific(x);
                break;
            }
            case 6: {
                cout << "Search for a node: ";
                cin >> x;
                int pos = l.search(x);
                if(pos==-1) {
                    cout << "Node not found!" << endl;
                } else {
                    cout << "Node found at position: " << pos << endl;
                }
                break;
            }
            case 7:
                cout << "Exiting program. Memory will be automatically freed.\n";
                break;

            default:
                cout << "Invalid choice! Please choose between 1 and 7.\n";
        }
    } while(option!=7);
    return 0;
}