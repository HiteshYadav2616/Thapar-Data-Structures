#include<iostream>
#include<vector>
using namespace std;
#define MAX 10000

int main() {
    int arr1[] = {1,2,3,4};
    int arr2[] = {3,4,5,6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int hash_set[MAX] = {0};

    for(int i=0; i<n1; i++) {
        hash_set[arr1[i]] = 1;
    }

    cout << "Common elements:" << endl;
    for(int i=0; i<n2; i++) {
        if(hash_set[arr2[i]]==1) {
            cout << arr2[i] << " ";
        }
    }
    return 0;
}