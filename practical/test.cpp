#include<iostream>
using namespace std;
class Student {
    public:
        int id;
        string name;
        string bname;
        string bid;

        Student(int id, string name, string bname, int bid) {
            this->bname = bname;
            this->bid = bid;
            this->id = id;
            this->name = name;
        }
};

Student* queue = nullptr;
int n;
int front = -1;
int rear = -1;

bool isEmpty() {
    if(front==-1) {
        return true;
    }
    return false;
}

bool isFull() {
    if((rear+1)%n==front) {
        return true;
    }
    return false;
}

void enqueue(Student s) {
    if(isFull()) {
        cout << "queue full!";
        return;
    }
    if(front==-1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear+1)%n;
    }
    queue[rear] = s;
}

void dequeue() {
    if(isEmpty()) {
        cout << "queue empty";
        return;
    }
    if(front==rear) {
        front =-1;
        rear = -1;
    } else {
        front = (front+1)%n;
    }
}

void peek() {
    if(isEmpty()) {
        cout << "queue empty";
        return;
    }
    cout << queue[front].id << queue[front].name << queue[front].bid << queue[front].bname;
}

void display() {
    if(isEmpty()) {
        cout << "queue empty";
        return;
    }

    for(int i=front; i<=rear; i++) {
        cout << "Student id: " << queue[i].id;
        cout << "Student name: " << queue[i].name;
        cout << "Book id: " << queue[i].bid;
        cout << "Book name: " << queue[i].bname;
    }
}

int main() {
    cout << "Enter size of the library request queue: ";
    cin >> n;

    while(true) {
        int x;
        cout << "Want to continue 1 for yes 0 for no";
        cin >> x;
        if(x==0) exit(0);
            int option;
    cout << "1. Add a request\n2. Cancel a request\n3. display pending requests\nChoose option>>";
    cin >> option;
    cin.ignore();
    switch(option) {
        case 1: {
        cout << "Enter details: ";
        int id;
        cout << "Enter student id: ";
        cin >> id;
        cin.ignore();
        string name;
        cout << "Enter student name: ";
        cin >> name;
        int bid;
        cout << "Enter book id: ";
        cin >> bid;
        cin.ignore();
        string bname;
        cout << "Enter book name: ";
        cin >> bname;

        Student s(id, name, bname, bid);
        enqueue(s);
        break;
        }
        case 2: {
            int Sid;
            cout << "Enter student id to cancel request: ";
            cin >> Sid;

            for(int i=front; i<=rear; i++) {
                if(queue[i].id==Sid) {
                    for(int j=i; i<=rear; j++) {
                        queue[j] = queue[j+1];
                    }
                    dequeue();
                }
            }
            break;
        }
        case 3: {
            cout << "Displaying pending requests:";
            display();
            break;
        }
        default: {
            cout << "Choose a valid option!";
        }
    }
}
    return 0;
}