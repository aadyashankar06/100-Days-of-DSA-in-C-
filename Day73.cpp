/*
Problem Statement:
Given a string s consisting of lowercase English letters, 
find and return the first character that does not repeat.
If all characters repeat, return '$'.

Input:
- A string s

Output:
- First non-repeating character OR '$'

Example:
Input: geeksforgeeks
Output: f
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);

    // Step 1: count frequency
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Step 2: find first non-repeating
    for (char c : s) {
        if (freq[c - 'a'] == 1) {
            cout << c;
            return 0;
        }
    }

    cout << '$';
    return 0;
}
