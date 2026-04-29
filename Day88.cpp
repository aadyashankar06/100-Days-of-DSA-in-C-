/*
Problem Statement:
Given n stalls and k cows, place the cows in stalls such that
the minimum distance between any two cows is maximized.

Input Format:
- First line: n k
- Second line: n space-separated stall positions

Output Format:
- Maximum possible minimum distance

Example:
Input:
5 3
1 2 8 4 9

Output:
3

Explanation:
Cows placed at positions 1, 4, and 8.
Minimum distance = 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if cows can be placed with minimum distance = dist
bool canPlaceCows(vector<int>& stalls, int k, int dist) {

    int cows = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {

        if (stalls[i] - lastPos >= dist) {
            cows++;
            lastPos = stalls[i];
        }

        if (cows >= k)
            return true;
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);

    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    // Sort stall positions
    sort(stalls.begin(), stalls.end());

    int left = 1;
    int right = stalls[n - 1] - stalls[0];

    int ans = 0;

    // Binary Search on answer
    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (canPlaceCows(stalls, k, mid)) {
            ans = mid;
            left = mid + 1; // try larger distance
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
