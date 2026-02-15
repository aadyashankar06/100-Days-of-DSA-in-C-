/*
Problem:
Check whether a given square matrix is an Identity Matrix.

An identity matrix has:
- 1s on the main diagonal
- 0s everywhere else
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int A[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    bool identity = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j && A[i][j] != 1) {
                identity = false;
                break;
            }

            if (i != j && A[i][j] != 0) {
                identity = false;
                break;
            }
        }
        if (!identity) break;
    }

    if (identity)
        cout << "Identity Matrix";
    else
        cout << "Not an Identity Matrix";

    return 0;
}
