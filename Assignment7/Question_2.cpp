#include<iostream>
using namespace std;

void minMaxSelectionSort(int arr[], int n) {
    int l=0, h=n-1;

    while(l<h) {
        int min_i=l;
        int max_i=h;

        for(int i=0; i<=h; i++) {
            if(arr[min_i]>arr[i]) min_i = i;
            if(arr[max_i]<arr[i]) max_i = i;
        }

        if(max_i==l) max_i=min_i;

        int temp = arr[min_i];
        arr[min_i] = arr[l];
        arr[l] = temp;

        temp = arr[max_i];
        arr[max_i] = arr[h];
        arr[h] = temp;

        l++; h--;

    }
}
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

    minMaxSelectionSort(arr,n);
    cout << endl << "After sorting:" << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}