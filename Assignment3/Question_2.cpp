#include<iostream>
#include<string>
using namespace std;

char* stack = nullptr;
int capacity = 0;
int main() {
    string str1;
    cout << "Enter a string: ";
    cin >> str1;

    cout << "Original string: " << str1 << endl;
    int size = str1.length();
    stack = new char[size];

    for(char c : str1) {
        stack[capacity++] = c;
    }

    string temp = "";
    for(int i=0; i<size; i++) {
        temp += stack[--capacity];
    }

    cout << "Reversed string: " << temp << endl;
    return 0;
}