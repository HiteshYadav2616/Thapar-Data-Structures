#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter length of the array: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " elements:" << endl;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int count = 0;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i]>arr[j]) {
                count++;
            }
        }
    }
    cout << "Number of inversions: " << count << endl;

    return 0;
}