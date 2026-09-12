#include<iostream>
#include<queue>
using namespace std;

int main() {
    string str;
    cout << "Enter sequence of characters: ";
    cin >> str;

    queue<char> q;
    int freq[26] = {0};
    for(char ch : str) {
        freq[ch-'a']++;
        q.push(ch);
    }

    int flag = 0;
    while(!q.empty()) {
        if(freq[q.front()-'a']==1) {
            cout << "first non-repeating character: " << q.front() << endl;
            flag = 1;
            break;
        } else {
            q.pop();
        }
    }
    if(!flag) {
        cout << "No non-repeating character available!" << endl;
    }
    return 0;
}