#include<iostream>
using namespace std;

int main() {
    int* arr = nullptr;
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    arr = new int[n];
    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Original array:" << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    for(int i=1; i<n; i++) {
        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    cout << endl;
    cout << "After sorting:" << endl;
        for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}