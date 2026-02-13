/*
Problem:
Write a program to perform addition of two matrices having the same dimensions.

Input:
- First line: m n (rows and columns)
- Next m lines: first matrix
- Next m lines: second matrix

Output:
- Resultant matrix after addition
*/

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int A[100][100], B[100][100], C[100][100];

    // Input first matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Input second matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    // Add matrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print result matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
