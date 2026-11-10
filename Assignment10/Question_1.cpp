#include<iostream>
using namespace std;
#define MAX 100000

bool findDuplicates(int arr[], int n) {
    int hash_set[MAX] = {0};
    for(int i=0; i<n; i++) {
        if(hash_set[arr[i]]==1) return true;
        hash_set[arr[i]]=1;
    }
    return false;
}

int main() {
    int arr[] = {1,2,3,5, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(findDuplicates(arr, n)) {
        cout << "Yes, array contains duplicates!" << endl;
    } else {
        cout << "No, array doesn't contains duplicates" << endl;
    }
    return 0;
}