#include<iostream>
using namespace std;

class Triplet {
    public:
        int row;
        int col;
        int val;
};

void matrixDisplay(Triplet* t, int size) {
    int row = t[0].row;
    int col = t[0].col;
    int k = 1;
     for(int i=1; i<row; i++) {
        for(int j=1; j<col; j++) {
            if(i==t[k].row && j==t[k].col && k<size) {
                cout << t[k].val << " ";
                k++;
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
     }
}
void tripletDisplay(Triplet* t, int size) {
    for(int i=0; i<size; i++) {
        cout << t[i].row << " | " << t[i].col << " | " << t[i].val << endl;
    }
    matrixDisplay(t, size);
}

void sortTriplet(Triplet* t, int size) {
    for(int i=1; i<t[0].row-1; i++) {
        for(int j=1; j<t[0].col-1-i; j++) {
            if(t[j].row > t[j+1].row) {
                Triplet temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
        tripletDisplay(t, size);
    }
}
void transpose(Triplet* t,int size) {
    Triplet* temp = new Triplet[size];

    for(int i=0; i<size; i++) {
        temp[i].row = t[i].col;
        temp[i].col = t[i].row;
        temp[i].val = t[i].val;
    }
    sortTriplet(temp, size);
    //tripletDisplay(temp, size);
    //matrixDisplay(temp, size);
}

void addition(Triplet* t, int size, Triplet* t1, int size2) {
    Triplet* temp = new Triplet[size + size2];
    temp[0].row = t[0].row;
    temp[0].col = t[0].col;

    int i=1;
    for(i; i<size; i++) {
        temp[i] = t[i];
    }

    for(int j=1; j<size2; j++) {
        int flag = 0;
        for(int k=1; k<i; k++) {
            if(t1[j].row == temp[k].row) {
                if(t1[j].col == temp[k].col) {
                    temp[k].val += t1[j].val;
                    flag = 1;
                }
            }
        }
        if(flag==0) {
            temp[i++] = t1[j];
        }
    }
    temp[0].val = i-1;
   tripletDisplay(temp, i);
}

void multiplication(Triplet* t, int size, Triplet* t1, int size2) {

}

int main() {
    int rows;
    int cols;

    cout << "Enter rows and columns of the sparse matrix: ";
    cin >> rows;
    cin >> cols;

    int n;
    cout << "How many elements you want to enter: ";
    cin >> n;

    int size = n+1;
    Triplet* t = new Triplet[size];
    t[0].row = rows;
    t[0].col = cols;
    t[0].val = n;

    cout << "Enter elements in sparse matrix:" << endl;
    for(int i=1; i<size; i++) {
        cout << "Element " << i << endl;
        cout << "Enter row index:";
        cin >> t[i].row;
        cout << "Enter column index:";
        cin >> t[i].col;
        cout << "Enter value:";
        cin >> t[i].val;
    }

    int option;
    cout << "\n1. Transpose of Sparse matrix\n2. Addition of Sparse matrix\n3. Multiplication of Sparse matrix\n>>Choose option:";
    cin >> option;

    switch(option) {
        case 1: {
            transpose(t, size);
            break;
        }
        case 2:
        cout << "Create another sparse matrix (taking rows and cols same):" << endl;
        cout << "How many elements you want to enter: ";
        int num;
        cin >> num;

        int size2 = num+1;
        Triplet* t1 = new Triplet[size2];
        t1[0].row = rows;
        t1[0].col = cols;
        t1[0].val = num;

        cout << "Enter elements:" << endl;
        for(int i=1; i<size2; i++) {
            cout << "Element " << i << endl;
            cout << "Enter row index:";
            cin >> t1[i].row;
            cout << "Enter column index:";
            cin >> t1[i].col;
            cout << "Enter value:";
            cin >> t1[i].val;
        }

        addition(t, size, t1, size2);
    }

    return 0;
}