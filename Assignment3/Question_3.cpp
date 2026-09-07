#include<iostream>
#include<string>
using namespace std;

char* stack = nullptr;
int cap = 0;

int main() {
    string str1 = "({{[]}})";

    int size = str1.length();
    stack = new char[size];
    for(int i=0; i<str1.length(); i++) {
        if(str1[i]=='(' || str1[i]=='[' || str1[i]=='{') {
            stack[cap++] = str1[i];

        } else if(str1[i]==')' && stack[cap-1]=='(' || str1[i]=='}' && stack[cap-1]=='{' || str1[i]==']' && stack[cap-1]=='[') {
            cap--;
        } else {
            cout << "Invalid paranthesis!" << endl;
            delete[] stack;
            exit(0);
        }
    }

    
    if(cap>0) {
        cout << "Invalid paranthesis!" << endl;
    } else {
        cout << "Valid paranthesis!" << endl;
    }

    delete[] stack;
    return 0;
}