/* 5) Write a program
    to find sum of every row and column
    in a two-dimensional array*/

#include <iostream>
using namespace std;

int main() {
    int row, col;
    cout << "Enter rows and columns of matrix: ";
    cin >> row;
    cin >> col;

    int** matrix = new int*[row];
    for(int i=0; i<row; i++) {
        matrix[i] = new int[col];
    }

    //insert elements
    cout << "Enter elements:" << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> matrix[i][j];       
        }
    }
    
    //sum of rows
    int* sumRow = new int[row];
    for(int i=0; i<row; i++) {
        sumRow[i] = 0;
        for(int j=0; j<col; j++) {
             sumRow[i] += matrix[i][j];       
        }
    }

    //sum of cols
    int* sumCol = new int[col];
    for(int i=0; i<col; i++) {
        sumCol[i] = 0;
        for(int j=0; j<row; j++) {
            sumCol[i] += matrix[j][i];
        }
    }

    //display
    cout << "Original matrix:" << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << matrix[i][j] << " ";       
        }
        cout << endl;
    }

    cout << "Sum of Rows:" << endl;
    for(int i=0; i<row; i++) {
        cout << sumRow[i] << " ";
    }
    cout << endl << endl;

    cout << "Sum of columns:" << endl;
    for(int i=0; i<col; i++) {
        cout << sumCol[i] << " ";
    }
    cout << endl;

    return 0;
}