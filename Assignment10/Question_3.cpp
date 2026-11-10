#include<iostream>
using namespace std;
#define MAX 1000

int main() {
    int arr[] = {2, 3, 2, 4, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int hash_map[MAX] = {0};

    for(int i : arr) {
        hash_map[i]++;
    }

    cout << "Element -> Frequency" << endl;

    for(int i=0; i<MAX; i++) {
        if(hash_map[i]>0)
        cout << i << " -> " << hash_map[i] << endl;
    }
    return 0;
}