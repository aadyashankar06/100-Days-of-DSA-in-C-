/*
Problem Statement:
Given a string s consisting of lowercase letters, find the first repeated character.
A character is repeated if it appears more than once.
Return the character whose second occurrence has the smallest index.

Input:
- A string s

Output:
- First repeated character OR -1

Example:
Input: geeksforgeeks
Output: e
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<bool> seen(26, false);

    for (char c : s) {
        if (seen[c - 'a']) {
            cout << c;
            return 0;
        }
        seen[c - 'a'] = true;
    }

    cout << -1;
    return 0;
}
