#include<iostream>
#include<stack>
using namespace std;

int precedence(char ch) {
    switch(ch) {
        case '^':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return 0;
    }
}

bool isOperand(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9));
}

string postfix(string exp) {
    stack<char> s;
    string pos;
    
    for(char c : exp) {
        if(isOperand(c)) {
            pos += c;
        
        } else if(c == '(') {
            s.push(c);

        } else if(c == ')') {
            while(!s.empty() && s.top()!='(') {
                pos += s.top();
                s.pop();
            }
            s.pop();

        } else {
            while(!s.empty() && s.top() != '(' && precedence(c) <= precedence(s.top())) {
                pos += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty()) {
        pos += s.top();
        s.pop();
    }

    return pos;
}
int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;
    cout << "Infix expression: " << exp << endl;
    cout << "Postfix expression: " << postfix(exp) << endl;;
    return 0;
}