/*
Problem:
Given an array of integers, find two elements whose sum is closest to zero.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    int minSum = 1000000000;
    int a = 0, b = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            a = arr[left];
            b = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    cout << a << " " << b;

    return 0;
}
