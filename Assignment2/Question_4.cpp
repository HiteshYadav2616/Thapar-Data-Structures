#include<iostream>
#include<string>
#include <set>   //used set to store vowels, accessing character is faster o(1)
using namespace std;

string concat(string str1, string str2) {
    string temp = "";
    for(int i=0; i<str1.length(); i++) {
        temp += str1[i];
    }

    for(int j=0; j<str2.length(); j++) {
        temp += str2[j];
    }
    return temp;
}

string rev(string str) {
    int i = 0;
    int j = str.length()-1;
    while(i<j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j++;
    }
    return str;
}

string removeVowels(string str) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string temp = "";
    for(int i=0; i<str.length(); i++) {
        if(vowels.find(str[i]) == vowels.end()) {
            temp += str[i];
        }
    }
    return temp;
}

string sortStr(string str) {
    for(int i=0; i<str.length()-1; i++)  {
        for(int j=0; j<str.length()-i-1; j++) {
            char a = str[j];
            char b = str[j + 1];

            if (a >= 'A' && a <= 'Z')               //changing ascii values according to there lower cases
                a += 32;
            if (b >= 'A' && b <= 'Z')
                b += 32;
                
            if (a > b) {
                char ch = str[j];
                str[j] = str[j+1];
                str[j+1] = ch;
            }
        }
    }
    return str;
}

int main() {
    int option;
    cout << "1. Concatenate one string to another string\n2. Reverse string\n3. Delete all vowels from the string\n4. Sort the string in alphabetical order\n5. Convert a character from uppercase to lowercase\n>>Choose option: ";
    cin >> option;
    cin.ignore();
    
    switch(option) {
        case 1: {
            string str;
            cout << "Enter a string: ";
            getline(cin, str);
            cout << "Original string: " << str << endl;

            string temp;
            cout << "Enter another string: ";
            getline(cin, temp);
            cout << "Another string: " << temp << endl;
            cout << "After concatenating: " << concat(str, temp) << endl;
            break;
        }
        case 2: {
            string str;
            cout << "Enter a string: ";
            getline(cin, str);
            cout << "Original string: " << str << endl;
            cout << "Reversed string: " << rev(str) << endl;
            break;
        }
        case 3: {
            string str;
            cout << "Enter a string: ";
            getline(cin, str);
            cout << "Original string: " << str << endl;
            cout << "After deleting vowels: " << removeVowels(str) << endl;
            break;
        }
        case 4: {
            string str;
            cout << "Enter a string: ";
            getline(cin, str);
            cout << "Original string: " << str << endl;
            cout << "After sorting: " << sortStr(str) << endl;
            break;
        }
        case 5: {
            char ch;
            cout << "Enter a capital character: ";
            cin >> ch;
            cout << "Original char: " << ch << endl;
            ch += 32;
            cout << "Lower case: " << ch << endl;
            break;
        }
        default: {
            cout << "Choose valid option!" << endl;
        }
    }
    return 0;
}