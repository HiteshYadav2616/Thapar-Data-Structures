#include <iostream>
using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int main() {

    int option;

    cout << "Store elements in-" << endl;
    cout << "\n1. Diagonal matrix"
         << "\n2. Tri-diagonal matrix"
         << "\n3. Lower triangular matrix"
         << "\n4. Upper triangular matrix"
         << "\n5. Symmetric matrix"
         << "\n>> Choose option: ";

    cin >> option;

    switch (option) {

        case 1: {
            int rows, cols;

            cout << "Enter dimensions of diagonal matrix: ";
            cin >> rows >> cols;

            if (rows != cols) {
                cout << "Rows and columns must be equal!" << endl;
                break;
            }

            int* diagonalMatrix = new int[rows];

            cout << "Enter elements:" << endl;
            for (int i = 0; i < rows; i++) {
                cin >> diagonalMatrix[i];
            }

            cout << endl << "Diagonal matrix:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i == j) {
                        cout << diagonalMatrix[i] << " ";
                    }
                    else {
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
            delete[] diagonalMatrix;
            break;
        }

        case 2: {
            int rows, cols;

            cout << "Enter dimensions of Tri-Diagonal matrix: ";
            cin >> rows >> cols;

            if (rows != cols) {
                cout << "Rows and columns must be equal!" << endl;
                break;
            }

            int size = (3 * rows) - 2;
            int* triDiagonal = new int[size];

            cout << "Enter elements:" << endl;
            for (int i = 0; i < size; i++) {
                cin >> triDiagonal[i];
            }

            cout << endl << "Tri-Diagonal matrix:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {

                    if (i == j) {
                        cout << triDiagonal[3 * i] << " ";
                    }
                    else if (i + 1 == j) {
                        cout << triDiagonal[(3 * i) + 1] << " ";
                    }
                    else if (j + 1 == i) {
                        cout << triDiagonal[(3 * i) - 1] << " ";
                    }
                    else {
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
            delete[] triDiagonal;
            break;
        }

        case 3: {
            int rows, cols;

            cout << "Enter dimensions of lower triangular matrix: ";
            cin >> rows >> cols;

            if (rows != cols) {
                cout << "Rows and columns must be equal!" << endl;
                break;
            }

            int size = (rows * (rows + 1)) / 2;
            int* lowerTriangular = new int[size];

            cout << "Enter elements:" << endl;
            for (int i = 0; i < size; i++) {
                cin >> lowerTriangular[i];
            }

            cout << endl << "Lower triangular matrix:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {

                    if (i >= j) {
                        int index = (i * (i + 1)) / 2 + j;
                        cout << lowerTriangular[index] << " ";
                    }
                    else {
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
            delete[] lowerTriangular;
            break;
        }

        case 4: {
            int rows, cols;

            cout << "Enter dimensions of upper triangular matrix: ";
            cin >> rows >> cols;

            if (rows != cols) {
                cout << "Rows and columns must be equal!" << endl;
                break;
            }

            int size = (rows * (rows + 1)) / 2;
            int* upperTriangular = new int[size];

            cout << "Enter elements:" << endl;
            for (int i = 0; i < size; i++) {
                cin >> upperTriangular[i];
            }

            cout << endl << "Upper triangular matrix:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {

                    if (i <= j) {
                        int index = (i * ((2 * rows) - i + 1)) / 2 + (j - i);
                        cout << upperTriangular[index] << " ";
                    }
                    else {
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
            delete[] upperTriangular;
            break;
        }

        case 5: {
            int rows, cols;

            cout << "Enter dimensions of symmetric matrix: ";
            cin >> rows >> cols;

            if (rows != cols) {
                cout << "Rows and columns must be equal!" << endl;
                break;
            }

            int size = (rows * (rows + 1)) / 2;
            int* symmetric = new int[size];

            cout << "Enter elements:" << endl;
            for (int i = 0; i < size; i++) {
                cin >> symmetric[i];
            }

            cout << endl << "Symmetric matrix:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int index = (max(i, j) * (max(i, j) + 1)) / 2 + min(i, j);
                    cout << symmetric[index] << " ";
                }
                cout << endl;
            }
            delete[] symmetric;
            break;
        }
        default: {
            cout << "Choose a valid option!" << endl;
        }
    }
    return 0;
}