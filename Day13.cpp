/*
Problem:
Traverse a rectangular matrix in clockwise spiral order
starting from the outer boundary and moving inward.

Input:
- First line: r c (rows and columns)
- Next r lines: matrix elements

Output:
- Elements printed in spiral order
*/

#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    int A[100][100];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> A[i][j];
        }
    }

    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

    while (top <= bottom && left <= right) {

        // top row
        for (int j = left; j <= right; j++)
            cout << A[top][j] << " ";
        top++;

        // right column
        for (int i = top; i <= bottom; i++)
            cout << A[i][right] << " ";
        right--;

        // bottom row
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                cout << A[bottom][j] << " ";
            bottom--;
        }

        // left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << A[i][left] << " ";
            left++;
        }
    }

    return 0;
}
