/*
Problem:
Implement Binary Search Iterative.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)
- Third line: target element to search

Output:
- Print index of target if found
- Otherwise print -1

Example:
Input:
5
12 22 25 34 64
25

Output:
2
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    // Input sorted array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int left = 0;
    int right = n - 1;

    int index = -1;

    // Iterative Binary Search
    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            index = mid;
            break;
        }

        else if (arr[mid] < target) {
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }

    cout << index;

    return 0;
}
