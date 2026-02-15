/*
Problem:
Given a matrix, calculate the sum of its primary diagonal elements.
Primary diagonal elements are where row index == column index.
*/

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int A[100][100];
    int sum = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];

            if (i == j) {
                sum += A[i][j];
            }
        }
    }

    cout << sum;

    return 0;
}
