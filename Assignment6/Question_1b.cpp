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
                Node* nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }
        }
        void insertAtBegin(int data) {
            Node* newNode = new Node(data);
            if(head==nullptr) {
                head = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
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
            newNode->prev = curr;
        }

        void insertBefore(int data, int x) {
            if(head==nullptr) return;
            if(head->data==x) {
                insertAtBegin(data);
                return;
            }
            Node* newNode = new Node(data);
            Node* curr = head;
            while(curr->next != nullptr && curr->next->data != x) {
                curr = curr->next;
            }
            if(curr->next!=nullptr) {
                newNode->next = curr->next;
                curr->next->prev = newNode;
                curr->next = newNode;
                newNode->prev = curr;

            } else {
                cout << "Element " << x << " is not in the list" << endl;
                delete newNode;
            }
        }
        void insertAfter(int data, int x) {
            Node* newNode = new Node(data);
            Node* curr = head;
            while(curr != nullptr && curr->data != x) {
                curr = curr->next;
            }
            if(curr!=nullptr) {
                newNode->next = curr->next;
                if(curr->next!=nullptr)
                curr->next->prev = newNode;
                curr->next = newNode;
                newNode->prev = curr;
            } else {
                cout << "Element " << x << " is not in the list" << endl;
                delete newNode;
            }
        }

        void deleteBegin() {
            if(head==nullptr) {return;}
            Node* temp = head;
            head = head->next;
            if(head!=nullptr)
            head->prev = nullptr;
            delete temp;
        }

        void deleteSpecific(int x) {
            if(head==nullptr) {return;}
            if(head->data==x) {
                deleteBegin();
                return;
            }
            Node* curr = head;
            while(curr->next != nullptr && curr->next->data != x) {
                curr = curr->next;
            }
            if(curr->next != nullptr) {
                Node* temp = curr->next;
                curr->next = temp->next;
                if(temp->next!=nullptr)
                temp->next->prev = curr;
                delete temp;
            }
        }
        int search(int x) {
            Node* curr = head;
            int count = 1;
            while(curr!=nullptr) {
                if(curr->data==x) {
                    return count;
                }
                count++;
                curr = curr->next;
            }
            return -1;
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
    DoublyLinkedList l;
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
                l.deleteSpecific(x);
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