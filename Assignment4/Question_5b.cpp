#include<iostream>
#include<queue>
using namespace std;

queue<int> q;

bool isEmpty()  {
    return q.empty();
}

void push(int x) {
    q.push(x);
    for(int i=0; i<q.size()-1; i++) {
        q.push(q.front());
        q.pop();
    }
}

void pop() {
    if(isEmpty()) {
        cout << "Queue is already empty!" << endl;
        return;
    }
    q.pop();
}

void peek() {
    if(isEmpty()) {
        cout << "Queue is already empty!" << endl;
        return;
    }
    cout << q.front() << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    queue<int> temp = q;
    cout << "Stack (top to bottom): ";
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {

    while(true) {
        int option;
        cout << "\n1. push()\n2. pop()\n3. isEmpty()\n4. display()\n5. peek()\n6. Exit\n>>Choose option: ";
        cin >> option;

        switch(option) {
            case 1: {
                int x;
                cout << "Enter element to insert: ";
                cin >> x;
                push(x);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                cout << boolalpha << isEmpty() << endl;
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
                peek();
                break;
            }
            case 6: {
                exit(0);
            }
            default: {
                cout << "Invalid option!" << endl;
            }
        }
    }
    return 0;
}