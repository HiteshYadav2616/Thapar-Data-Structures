#include<iostream>
#include<stack>
#include<cmath>
#include<string>
using namespace std;
bool isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

int eval(string exp) {
    stack<int> s;
    for(int i=0; i<exp.length(); i++) {
        char ch = exp[i];
        if(isOperand(ch)) {
            int x = ch - '0';
            s.push((x));
        
        } else {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();

            if(ch=='+') {
                s.push(val2 + val1);
            } else if(ch=='-') {
                s.push(val2 - val1);
            } else if(ch == '*') {
                s.push(val2 * val1);
            } else if(ch == '/') {
                s.push(val2 / val1);
            } else {
                s.push((int)pow(val2, val1));
            }
        }
    }
    return s.top();
}
int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << eval(exp);
    return 0;
}