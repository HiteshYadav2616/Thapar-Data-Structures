#include<iostream>
using namespace std;

int* queue = nullptr;
int n;
int rear = -1;
int front = -1;

bool isFull() {
    return rear+1==n;
}

bool isEmpty() {
    return front==-1 || front > rear;
}

void enqueue(int x) {
    if(isFull()) {
        cout << "queue is already a full!" << endl;
        return;
    }

    if(front==-1) {
        front = 0;
    }

    queue[++rear] = x;
}

void dequeue() {
    if(isEmpty()) {
        cout << "queue is already empty!" << endl;
        return;
    }

    front++;
}

void display() {
    int temp = front;
    while(temp <= rear) {
        cout << queue[temp++];
    }
}

int peek() {
    return queue[front];
}

int main() {
    cout << "Enter size of the queue: ";
    cin >> n;

    queue = new int[n];

    while(true) {
        int option;
        cout << "1. enqueue()\n2. dequeue()\n3. isEmpty()\n4. isFull()\n5. display()\n6. peek()\n7. Exit\nChoose option: ";
        cin >> option;

        switch(option) {
            case 1: {
                int x;
                cout << "Enter value to insert: ";
                cin >> x;
                enqueue(x);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3: {
                cout << (isEmpty() ? "true" : "false") << endl;
                break;
            }
            case 4: {
                cout << (isFull() ? "true" : "false") << endl;
                break;
            }
            case 5: {
                display();
                break;
            }
            case 6: {
                cout << peek() << endl;
                break;
            }
            case 7: {
                cout << "Program exited!" << endl;
                delete[] queue;
                exit(0);
            }
            default: {
                cout << "Invalid option!";
            }
        }
    }
    
    return 0;
}