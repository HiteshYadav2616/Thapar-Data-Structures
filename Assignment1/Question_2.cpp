/*2) Design the logic to remove the duplicate elements from any array and
 after the deletion the array should contain the unique elements.*/

#include <iostream>
#include <set>
using namespace std;

int* arr = nullptr;
int capacity;  //actual number of elements
int n;      //size of the array

void display() {
    for(int i=0; i<capacity; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void del(int id) {
    for(int i=id; i<capacity-1; i++) {
        arr[i] = arr[i+1];
    }
    capacity--;
}
void removeDuplicates() {
    set<int> s;
    for(int i=0; i<capacity; i++) {
        if(s.find(arr[i]) != s.end()) {
            del(i);
        }
        s.insert(arr[i]);
    }
}
int main() {
    cout << "Enter size of the array: ";
    cin >> n;
    arr = new int[n];       //dynamically allocating size to the array

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

    removeDuplicates();     //remove duplicates function

    cout << "After removing duplicates:" << endl;
    display();
    return 0;
}