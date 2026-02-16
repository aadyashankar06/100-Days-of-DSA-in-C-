/*
Problem:
Given an array of integers, count the frequency of each distinct element
and print in the format element:count.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {

        // Check if already counted before
        bool counted = false;
        for (int k = 0; k < i; k++) {
            if (arr[k] == arr[i]) {
                counted = true;
                break;
            }
        }

        if (counted) continue;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        cout << arr[i] << ":" << count << " ";
    }

    return 0;
}
