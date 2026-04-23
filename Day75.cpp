/*
Problem Statement:
Given an array with positive and negative integers,
find the length of the longest contiguous subarray with sum = 0.

Input:
- Array arr[]

Output:
- Length of longest subarray with sum = 0

Example:
Input: 15 -2 2 -8 1 7 10 23
Output: 5
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> mp; // sum → index
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        // Case 2: seen before
        if (mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i; // store first occurrence
        }
    }

    cout << maxLen;
    return 0;
}
