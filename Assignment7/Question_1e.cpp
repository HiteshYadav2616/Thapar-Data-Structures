#include<iostream>
using namespace std;

int quickSort(int arr[], int l, int h) {
    int pivot = arr[l];
    int i=l, j=h;
    while(i<j) {
        while(i<=h && arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
        arr[l] = arr[j];
        arr[j] = pivot;

        return j;
}

void partition(int arr[], int l, int h) {
    if(l>=h) return;

    int p = quickSort(arr, l, h);
    partition(arr, l, p-1);
    partition(arr, p+1, h);
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

    partition(arr, 0, n-1);
    cout << endl << "After sorting:" << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}