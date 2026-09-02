#include <iostream>
using namespace std;

void linearSearch(int* arr, int n, int key) {
    for(int i=0; i<n; i++) {
        if(key==arr[i]) {
            cout << "Element found at index " << i << endl;
        }
    }
}

void binarySearch(int* arr, int n, int key) {
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = (high+low)/2;

        if(key==arr[mid]) {
            cout << "Element found at index " << mid;
            return;
        } else if(key > arr[mid]) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    cout << "Element not found!" << endl;
    return;
}

void arrSort(int* arr, int n) {
    //bubble sort
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j+1] < arr[j]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter length of the array: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " elements:" << endl;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter element to find: ";
    cin >> x;

    int choice;
    cout << "\n1. Linear Search\n2. Binary Search\n>> ";
    cin >> choice;

    if(choice==1) {
        linearSearch(arr, n, x);
    } else if(choice==2) {
        arrSort(arr, n);
    
    cout << "Sorted array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    binarySearch(arr, n, x);
    } else {
        cout << "Invalid option!" << endl;
    }
    
    return 0;
}