#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    queue<int> tempq;
    int n;
    cout << "How many elements you want to enter: ";
    cin >> n;

    for(int i=0; i<n; i++) {
        int ele;
        cin >> ele;
        q.push(ele);
    }

    int firstHalf = q.size()%2==0 ? q.size()/2 : (q.size()/2)+1;
    int secondHalf = q.size() - firstHalf;

    for(int i=0; i<firstHalf; i++) {
        tempq.push(q.front());
        q.pop();
    }

    for(int i=0; i<secondHalf; i++) {
        q.push(tempq.front());
        tempq.pop();

        q.push(q.front());
        q.pop();
    }

    while(!tempq.empty()) {
        q.push(tempq.front());
        tempq.pop();
    }

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}