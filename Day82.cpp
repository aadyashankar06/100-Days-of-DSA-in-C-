/*
Problem:
Implement Bubble Sort.

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

    // Read array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {

        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Optimization:
        // If no swapping happens, array is already sorted
        if (!swapped)
            break;
    }

    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
