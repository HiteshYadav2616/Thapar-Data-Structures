#include<iostream>
using namespace std;

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
    if(n<=0) {
        cout << "Invalid size input!";
        return -1;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " elements:" << endl;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    arrSort(arr, n);
    int count = 1;
    for(int i=1; i<n; i++) {
        if(arr[i] != arr[i-1]) {
            count++;
        }
    }
    cout << count << " distinct elements are in the array" << endl;
    return 0;
}