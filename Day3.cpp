/*
Problem:
Implement linear search to find key k in an array.
Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

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

    int k;
    cin >> k;

    int comparisons = 0;
    bool found = false;

    for (int i = 0; i < n; i++) {
        comparisons++;

        if (arr[i] == k) {
            cout << "Found at index " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Not Found" << endl;
    }

    cout << "Comparisons = " << comparisons;

    return 0;
}
