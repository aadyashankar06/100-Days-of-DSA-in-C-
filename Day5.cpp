/*
Problem:
A system receives two separate logs of user arrival times from two different servers.
Each log is already sorted in ascending order.
Create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers

*/

#include <iostream>
using namespace std;

int main() {
    int p;
    cin >> p;

    int a[100];
    for (int i = 0; i < p; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    int b[100];
    for (int i = 0; i < q; i++) {
        cin >> b[i];
    }

    int i = 0, j = 0;

  
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            cout << a[i] << " ";
            i++;
        } else {
            cout << b[j] << " ";
            j++;
        }
    }

  
    while (i < p) {
        cout << a[i] << " ";
        i++;
    }

    while (j < q) {
        cout << b[j] << " ";
        j++;
    }

    return 0;
}
