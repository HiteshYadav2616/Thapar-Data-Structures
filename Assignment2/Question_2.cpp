#include<iostream>
using namespace std;

    
void bubbleSort(int* arr, int n) {
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

    cout << "Original array:" << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, n);
    
    cout << "Sorted array:" << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}