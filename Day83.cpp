/*
Problem:
Implement Selection Sort.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    // Input array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;

        // Find minimum element
        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap minimum element with current position
        swap(arr[i], arr[minIndex]);
    }

    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
