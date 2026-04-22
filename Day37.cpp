/*
Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

// Heapify up
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else break;
    }
}

// Heapify down
void heapifyDown(int i) {
    int n = heap.size();

    while (true) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < n && heap[left] < heap[smallest])
            smallest = left;

        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            i = smallest;
        } else break;
    }
}

// Insert
void insert(int x) {
    heap.push_back(x);
    heapifyUp(heap.size() - 1);
}

// Delete (remove min)
int deleteMin() {
    if (heap.empty())
        return -1;

    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return root;
}

// Peek
int peek() {
    if (heap.empty())
        return -1;
    return heap[0];
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            insert(x);
        }
        else if (op == "delete") {
            cout << deleteMin() << endl;
        }
        else if (op == "peek") {
            cout << peek() << endl;
        }
    }

    return 0;
}
