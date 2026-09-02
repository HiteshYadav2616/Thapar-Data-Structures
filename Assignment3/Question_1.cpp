#include<iostream>
using namespace std;

int* arr = nullptr;
int cap = 0;
int main() {
    int size;
    cout << "Enter size of the stack: ";
    cin >> size;

    arr = new int[size];
    while(true) {
        int option;
        cout << "\n1. push()\n2. pop()\n3. isEmpty()\n4. isFull()\n5. display()\n6. peek()\n7. Exit\n>>Choose option: ";
        cin >> option;

        switch(option) {
            case 1: {
                if(cap == size) {
                    cout << "Stack is already full!" << endl;
                    break;
                }
                int x;
                cout << "Enter element: ";
                cin >> x;
                arr[cap] = x;
                cap++;
                break;
            }
            case 2: {
                if(cap == 0) {
                    cout << "Stack is empty!" << endl;
                    break;
                }
                cap--;
                break;
            }
            case 3: {
                bool ans = (cap==0);
                cout << boolalpha << ans << endl;
                break;
            }
            case 4: {
                bool ans = (cap==size);
                cout << boolalpha << ans << endl;
                break;
            }
            case 5: {
                if(cap == 0) {
                    cout << "Stack is empty!" << endl;
                    break;
                }

                for(int i=cap-1; i>=0; i--) {
                    cout << arr[i] << " ";
                }
                break;
            }
            case 6: {
                if(cap == 0) {
                    cout << "Stack is empty!" << endl;
                    break;
                }
                
                cout << arr[cap-1] << endl;
                break;
            }
            case 7: {
                exit(0);
            }
            default: {
                cout << "Invalid option!" << endl;
            }
        }
    }
    return 0;
}