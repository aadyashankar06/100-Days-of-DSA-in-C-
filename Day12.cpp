/*
Problem:
Check whether a given matrix is symmetric.
A matrix is symmetric if it is square and element[i][j] = element[j][i].
*/

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int A[100][100];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // If not square, cannot be symmetric
    if (m != n) {
        cout << "Not a Symmetric Matrix";
        return 0;
    }

    bool symmetric = true;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != A[j][i]) {
                symmetric = false;
                break;
            }
        }
        if (!symmetric) break;
    }

    if (symmetric)
        cout << "Symmetric Matrix";
    else
        cout << "Not a Symmetric Matrix";

    return 0;
}
