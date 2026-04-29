/*
Problem:
Implement Insertion Sort.

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

    // Insertion Sort
    for (int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at correct position
        arr[j + 1] = key;
    }

    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
