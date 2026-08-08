#include <iostream>
#include <string>
using namespace std;

int* arr=nullptr;
int capacity;      //current number of elements
int n;      //size of the array

void display() {
    for(int i=0; i<capacity; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotateLeft(int pos) {
    for(int i=0; i<pos; i++) {
        int temp = arr[0];
        for(int j=0; j<capacity-1; j++) {
            arr[j] = arr[j+1];
        }
        arr[capacity-1] = temp;
    }
}

void rotateRight(int pos) {
    for(int i=0; i<pos; i++) {
        int temp = arr[capacity-1];
        for(int j=capacity-1; j>0; j--) {
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }
}

int main() {
    cout << "Enter size of the array: ";
    cin >> n;
    arr = new int[n];

    while(true) {    //while loop until user enters right number of elements
        cout << "How many elements you want to enter\n(choose between 1 to " << n << "): ";
        cin >> capacity;

        if (capacity > 0 && capacity <= n) {   //making sure that user enter's atleast one element
            break;
        }
    }

    for(int i=0; i<capacity; i++) {
        cin >> arr[i];
    }

    cout << "Original array:" << endl;
    display();

    char option;
    cout << "Want to rotate left(l) or right(r) : ";
    cin >> option;

    int pos;
    cout << "By how many positions: ";
    cin >> pos;

    string s;
    if(option=='l') {
        rotateLeft(pos);
        s = "left";
    } else if(option=='r') {
        rotateRight(pos);
        s = "right";

    } else {
        cout << "Invalid option!" << endl;
    }

    cout << "After " << pos << " " << s << " rotations:" << endl;
    display();
    return 0;
}