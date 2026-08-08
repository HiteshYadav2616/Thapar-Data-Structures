#include <iostream>
#include <cctype>  //for tolower() function
#include <cstdlib>  //for exit() function to exit form the program 
using namespace std;

int* arr = nullptr;
int capacity;   //current number of elements
int n;         //size of the array

int* create() {
    arr = new int[n];

    //initial entries of elements
    cout << "How many elements you want to enter initially\n(entries should be equal to or less than " << n << "): ";
    cin >> capacity;

    if (capacity < 0 || capacity > n) {
        cout << "Invalid number of elements!" << endl;
        capacity = 0;
        return arr;
    }

    for(int i=0; i<capacity; i++) {
        cin >> arr[i];
    }

    return arr;
}

void display() {
    if (arr == nullptr) {
    cout << "Create the array first!";
    return;
    }

    cout << "Elements:" << endl;
    for(int i=0; i<capacity; i++) {
        cout << arr[i] << " ";
    }
}

void insert(int id, int x) {
    if (arr == nullptr) {
    cout << "Create the array first!" << endl;
    return;
    }

    if(capacity==n) {
    cout << "Can't insert element, array is already full!" << endl;
    return;
    }

    if(id<0 || id>capacity) {
    cout << "Invalid index!";
    return;
    }
    
    for(int i=capacity-1; i>=id; i--) {
    arr[i+1] = arr[i];
    }
    arr[id] = x;
    capacity++;
}

int linear_search(int x) {
    for(int i=0; i<capacity; i++) {
    if(arr[i]==x) {
        return i;
        }
    }
    return -1;
}

void del(int x) {
    if (arr == nullptr) {
    cout << "Create the array first!";
    return;
    }

    if(capacity==0) {
        cout << "Array is already empty!";
        return;
    }
    int id = linear_search(x);
    if(id==-1) {
        cout << "Element not found!";
        return;
    }
    for(int i=id; i<capacity-1; i++) {
        arr[i] = arr[i+1];
    }
    capacity--;
}

int main() {
    while(true) {
        cout << "Choose an option:" << endl;
        cout << "1. Create array\n2. Display array\n3. Insert element\n4. Delete element\n5. Linear Search\n6. Exit\n>> ";
        int choice;
        cin >> choice;

        switch(choice) {
            case 1: {
                if(arr!=nullptr) {
                    cout << "Array is already created!" << endl;
                    cout << "Do you want to create a new Array (y/n): ";
                    char option;
                    cin >> option;
                    if(tolower(option) != 'y') {
                        break;
                    }
                    else {
                        delete[] arr;   //deallocating memory of the array
                        arr = nullptr;
                    }
                }
                cout << "Enter size of the array: ";
                cin >> n;
                if(n<=0) {
                    cout << "Invalid array size." << endl;
                    break;
                }
                create();
                cout << "Array created successfully!" << endl;
                break;
            }

            case 2: {
                display();
                break;
            }
            case 3: {
                cout << "Enter element to insert: ";
                int element;
                cin >> element;
                cout << "At which index you want to insert element: ";
                int id;
                cin >> id;
                insert(id, element);
                break;
            }

            case 4: {
                cout << "Enter element to delete: ";
                int num;
                cin >> num;
                del(num);
                break;
            }
            case 5: {
                if (arr == nullptr) {
                cout << "Create the array first!" << endl;
                break;
                }
                
                cout << "Enter the element to search: ";
                int x;
                cin >> x;
                int index = linear_search(x);
                if(index==-1)
                    cout << "Element not found.";
                else
                    cout << "Element found at index: " << index << endl;
                break;
            }
            case 6:
            delete[] arr;   //deallocating memory
                exit(0);

            default:
                cout << "Choose a valid option" << endl;
        }
        cout << endl;
    }
    return 0;
}