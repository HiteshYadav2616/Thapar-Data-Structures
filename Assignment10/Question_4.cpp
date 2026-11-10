#include<iostream>
#define MAX 1000
using namespace std;

int main() {
    int hash_map[MAX] = {0};
    int arr[] = {4, 5, 5, 1, 2, 0, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++) hash_map[arr[i]]++;

    cout << "First non-repeating character: ";
    for(int i=0; i<n; i++) {
        if(hash_map[arr[i]]==1) {
            cout << arr[i];
            break;
        }
    }
    return 0;
}