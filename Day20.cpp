/*
Problem:
Given an array of integers, count the number of subarrays whose sum is zero.
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> freq;

    int prefixSum = 0;
    int count = 0;

    freq[0] = 1; // important for subarrays starting from index 0

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (freq.find(prefixSum) != freq.end()) {
            count += freq[prefixSum];
        }

        freq[prefixSum]++;
    }

    cout << count;

    return 0;
}
