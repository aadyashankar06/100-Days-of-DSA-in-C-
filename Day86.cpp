/*
Problem:
Find the integer square root of a non-negative integer using Binary Search.

The integer square root of n is the greatest integer
such that (integer)^2 <= n.

Input:
- First line: integer n

Output:
- Integer square root of n

Examples:
Input:
64
Output:
8

Input:
20
Output:
4

Input:
1
Output:
1
*/

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long left = 0;
    long long right = n;
    long long ans = 0;

    while (left <= right) {

        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        // Perfect square
        if (square == n) {
            cout << mid;
            return 0;
        }

        // mid is possible answer
        if (square < n) {
            ans = mid;
            left = mid + 1;
        }

        // Search left half
        else {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
