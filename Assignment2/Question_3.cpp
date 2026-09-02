#include <iostream>
using namespace std;
void linearTime(int* arr, int n) {
    for(int i=0; i<n; i++) {
        if(arr[i] != i+1) {
            cout << "Missing number is: " << i+1 << endl;
            return;
        }
    }
}

void usingBinary(int* arr, int low, int mid, int high) {
    if(low>high) {
        cout << "Missing element is: " << mid+1 << endl;
        return;
    }
    mid = (low+high)/2;
    if(arr[mid]==mid+1) {
        usingBinary(arr, mid+1, mid, high);
    } else if(arr[mid]>mid+1) {
        usingBinary(arr, low, mid, mid-1);
    }
}

int main() {
    int n;
    cout << "Enter length of the array: ";
    cin >> n;
    if(n<=0) {
        cout << "Invalid size input!";
        return -1;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " elements (1 to " << n+1 << "):" << endl;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "1. Linear time\n2. Using Binary Search\n>> ";
    cin >> choice;

    if(choice==1) {
        linearTime(arr, n);
    } else if(choice==2) {
        usingBinary(arr, 0, (n-1)/2, n-1);
    } else {
        cout << "Invalid option!" << endl;
    }
    return 0;
}