#include <iostream>
#include <vector>
using namespace std;

void matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i][j] = 0; 
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter the number of rows for matrix A: ";
    cin >> rowsA;
    cout << "Enter the number of columns for matrix A: ";
    cin >> colsA;

    cout << "Enter the number of rows for matrix B: ";
    cin >> rowsB;
    cout << "Enter the number of columns for matrix B: ";
    cin >> colsB;

    if (colsA != rowsB) {
        cout << "Matrix multiplication is not possible with the given dimensions." << endl;
        return -1;
    }

    vector<vector<int>> A(rowsA, vector<int>(colsA));
    vector<vector<int>> B(rowsB, vector<int>(colsB));
    vector<vector<int>> C(rowsA, vector<int>(colsB));

    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cin >> B[i][j];
        }
    }

    matrixMultiply(A, B, C);

    cout << "Matrix A:" << endl;
    displayMatrix(A);

    cout << "Matrix B:" << endl;
    displayMatrix(B);

    cout << "Resultant Matrix C (A * B):" << endl;
    displayMatrix(C);

    return 0;
}
