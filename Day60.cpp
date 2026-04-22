#include <iostream>
#include <vector>

using namespace std;

string validateMinHeap(int n, const vector<int>& arr) {
    // A heap with 0 or 1 node is always valid
    if (n <= 1) return "YES";

    // We only need to check internal nodes (nodes with children)
    // The last internal node is at index (n-2)/2
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // Check left child
        if (leftChild < n && arr[i] > arr[leftChild]) {
            return "NO";
        }

        // Check right child
        if (rightChild < n && arr[i] > arr[rightChild]) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << validateMinHeap(n, arr) << endl;

    return 0;
}
