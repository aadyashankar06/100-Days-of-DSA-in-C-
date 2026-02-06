/*
Problem:
You are given two sorted arrays nums1 and nums2 with sizes m and n.
nums1 has extra space to hold elements of nums2.
Merge nums2 into nums1 so that the final array is sorted.

Input:
- First line: m (number of valid elements in nums1)
- Second line: m elements of nums1
- Third line: n (number of elements in nums2)
- Fourth line: n elements of nums2

*/

#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;

    int nums1[200];
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    int n;
    cin >> n;

    int nums2[200];
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    
    for (int x = 0; x < m + n; x++) {
        cout << nums1[x] << " ";
    }

    return 0;
}
