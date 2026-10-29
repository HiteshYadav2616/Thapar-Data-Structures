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

class LinkedList {
    Node* head;

    public:
        LinkedList() {head = nullptr;}
        ~LinkedList() {
            Node* curr = head;
            while(curr != nullptr) {
                Node* nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }
        }

        void insertAtBegin(int data) {
            Node* newNode = new Node(data);
            newNode->next = head;
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
                curr->next = newNode;
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
                curr->next = newNode;
            } 
        }

        void deleteBegin() {
            if(head==nullptr) {return;}
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        void deleteEnd() {
            if(head==nullptr) {return;}
            if(head->next==nullptr) {
                head=nullptr;
                return;
            }
            Node* curr = head;
            while(curr->next->next != nullptr) {
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = nullptr;
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
    LinkedList l;
    int choice, data, x, subChoice;

    do {
        cout << "a. (1) Insertion at the beginning\n";
        cout << "b. (2) Insertion at the end\n";
        cout << "c. (3) Insertion in between (Before/After a specific node)\n";
        cout << "d. (4) Deletion from the beginning\n";
        cout << "e. (5) Deletion from the end\n";
        cout << "f. (6) Deletion of a specific node\n";
        cout << "g. (7) Search for a node and display its position\n";
        cout << "h. (8) Display all the node values\n";
        cout << "   (9) Exit\n";
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                l.insertAtBegin(data);
                break;

            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                l.insertAtEnd(data);
                break;

            case 3:
                cout << "Where do you want to insert?\n";
                cout << "1. Before a specific node\n";
                cout << "2. After a specific node\n";
                cout << "Enter sub-choice (1 or 2): ";
                cin >> subChoice;
                cout << "Enter new node value to insert: ";
                cin >> data;
                cout << "Enter reference node value (e.g., 30): ";
                cin >> x;
                
                if (subChoice == 1) {
                    l.insertBefore(data, x);
                } else if (subChoice == 2) {
                    l.insertAfter(data, x);
                } else {
                    cout << "Invalid option!\n";
                }
                break;

            case 4:
                l.deleteBegin();
                break;

            case 5:
                l.deleteEnd();
                break;

            case 6:
                cout << "Enter the node value to delete (e.g., 60): ";
                cin >> x;
                l.deleteSpecific(x);
                break;

            case 7:
                cout << "Enter the node value to search: ";
                cin >> x;
                {
                    int pos = l.search(x);
                    if(pos == -1) {
                        cout << "Element " << x << " not found in the list.\n";
                    } else {
                        cout << "Element " << x << " found at position: " << pos << " from head.\n";
                    }
                }
                break;

            case 8:
                l.show();
                break;

            case 9:
                cout << "Exiting program. Memory will be automatically freed.\n";
                break;

            default:
                cout << "Invalid choice! Please choose between 1 and 9.\n";
        }
    } while(choice != 9);

    return 0;
}