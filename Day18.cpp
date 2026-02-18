/*
Problem:
Given an array of integers, rotate the array to the right by k positions.
*/

#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    k = k % n;

    // Reverse whole array
    reverseArray(arr, 0, n - 1);

    // Reverse first k elements
    reverseArray(arr, 0, k - 1);

    // Reverse remaining elements
    reverseArray(arr, k, n - 1);

    // Print rotated array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
