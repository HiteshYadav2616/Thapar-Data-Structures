#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int h) {
    int n1 = mid-l+1;
    int n2 = h-mid;

    int* temp1 = new int[n1];
    int* temp2 = new int[n2];

    for(int i=0; i<n1; i++) {
        temp1[i] = arr[l+i];
    }
    for(int i=0; i<n2; i++) {
        temp2[i] = arr[mid+1+i];
    }

    int i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        if(temp1[i]<temp2[j]) {
            arr[k] = temp1[i];
            i++;
        } else {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }
    while(i<n1) arr[k++] = temp1[i++];
    while(j<n2) arr[k++] = temp2[j++];

    delete[] temp1;
    delete[] temp2;
}
void mergeSort(int arr[], int l, int h) {
    if(l>=h) return;

    int mid = (l+h)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, h);
    merge(arr, l, mid, h);
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

    mergeSort(arr, 0, n-1);
    cout << endl << "After sorting:" << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}