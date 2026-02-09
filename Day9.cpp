/*
Problem:
A secret system stores code names in forward order.
To display them in mirror format, reverse the given string.

Input:
- Single line: a lowercase string (no spaces)

*/

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }

    cout << s;

    return 0;
}
