#include <iostream>
using namespace std;

void reverse(int* arr, int cap) {
    int* temp = new int[cap];
    for(int i=0; i<cap; i++) {
        temp[i] = arr[i];
    }
    for(int i=0; i<cap; i++) {
        arr[i] = temp[cap-1-i];
    }
    delete[] temp;
}

void arrayDisplay(int* arr, int cap) {
    for(int i=0; i<cap; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertMatrix(int** matrix, int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> matrix[i][j];
        }
    }
}
void matrixDisplay(int** matrix, int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << matrix[i][j] << " ";
        }
    cout << endl;
    }
    cout << endl;
}

int main() {
    int option;
    cout << "1. Reverse elements of an array\n2. Matrix multiplication\n3. Transpose of Matrix\nChoose option: ";
    cin >> option;

    switch(option) {
        case 1: {
            int* arr=nullptr;
            int n;      //size of the array
            int capacity;       //current number of elements
            cout << "Enter size of the array: ";
            cin >> n;
            arr = new int[n];
            cout << "How many elements you want to enter: ";
            cin >> capacity;

            if(capacity < 0 || capacity > n) {
                cout << "Invalid number of elements!";
                break;
            }

            cout << "Enter elements: " << endl;
            for(int i=0; i<capacity; i++) {
                cin >> arr[i];
            }

            cout << "Original Array:" << endl;
            arrayDisplay(arr, capacity);

            reverse(arr, capacity);

            cout << "Reversed Array:" << endl;
            arrayDisplay(arr, capacity);

            delete[] arr;   //deallocating memory
            break;
        }

        case 2: {
            //taking imput of dimensions
            int r1;
            int c1;
            cout << "Enter rows and columns of matrix 1: ";
            cin >> r1;
            cin >> c1;

            int r2, c2;
            cout << "Enter rows and columns of matrix 2: ";
            cin >> r2;
            cin >> c2;

            //checking dimensions of matrices are suitbale for multiplication
            if(r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0) {
                cout << "Invalid matrix dimensions!" << endl;
                break;
            }
            if(c1!=r2) {
                cout << "column size of matirx 1 should be equal to row size of matrix 2" << endl;
                break;
            }

            //initializing matrices
            int** matrix1 = new int*[r1];
            for(int i=0; i<r1; i++) {
                matrix1[i] = new int[c1];
            }

            int** matrix2 = new int*[r2];
            for(int i=0; i<r2; i++) {
                matrix2[i] = new int[c2];
            }

            //inserting elements in the matrices
            cout << "Enter elements for matrix 1:" << endl;
            insertMatrix(matrix1, r1, c1);

            cout << "Enter elements for matrix 2:" << endl;
            insertMatrix(matrix2, r2, c2);

            //initializing resultant matrix after multiplication
            int** result = new int*[r1];
            for(int i=0; i<r1; i++) {
                result[i] = new int[c2];
            }

            //matrix multiplication
            for(int i=0; i<r1; i++) {
                for(int j=0; j<c2; j++) {
                    result[i][j] = 0;
                    for(int k=0; k<c1; k++) {
                        result[i][j] += matrix1[i][k] * matrix2[k][j]; 
                    }
                }
            }

            //display matrices
            cout << "Matrix 1:" << endl;
            matrixDisplay(matrix1, r1, c1);
            
            cout << "Matrix 2:" << endl;
            matrixDisplay(matrix2, r2, c2);

            cout << "Multiplcation matrix:" << endl;
            matrixDisplay(result, r1, c2);
            

            //deallocating memory of all matrices after execution
            for(int i=0; i<r1; i++) {
                delete[] matrix1[i];
            }
            delete[] matrix1;

            for(int i=0; i<r2; i++) {
                delete[] matrix2[i];
            }
            delete[] matrix2;

            for(int i=0; i<r1; i++) {
                delete[] result[i];
            }
            delete[] result;
            break;
        }
        case 3: {
            int r;
            int c;
            cout << "Enter rows and columns of matrix: ";
            cin >> r;
            cin >> c;

            if(r <= 0 || c <= 0) {
                cout << "Invalid matrix dimensions!" << endl;
                break;
            }

            //initializing matrix
            int** mat = new int*[r];
            for(int i=0; i<r; i++) {
                mat[i] = new int[c];
            }

            //inserting elements
            cout << "Enter elements for matrix:" << endl;
            insertMatrix(mat, r, c);

            //transpose
            int** transpose = new int*[c];
            for(int i=0; i<c; i++) {
                transpose[i] = new int[r];
            }

            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    transpose[j][i] = mat[i][j];
                }
            }

            //display matrices
            cout << "Original matrix:" << endl;
            matrixDisplay(mat, r, c);

            cout << "Transpose matrix:" << endl;
            matrixDisplay(transpose, c, r);

            //deallocating memory of the matrix after execution
            for(int i=0; i<r; i++) {
                delete[] mat[i];
            }
            delete[] mat;

            for(int i=0; i<c; i++) {
                delete[] transpose[i];
            }
            delete[] transpose;
            break;
        }
        default:
            cout << "Invalid option" << endl;
    }
    return 0;
}