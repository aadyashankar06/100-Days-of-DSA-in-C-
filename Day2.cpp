/*
Problem:
Write a C++ program to delete the element at a given 1-based position pos
from an array of n integers. Shift remaining elements to the left.


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

    int pos;
    cin >> pos;

    
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    
    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
