/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10

Explanation:
Push all queue elements into a stack, then pop them back into the queue.
Since stack follows LIFO order, the queue becomes reversed.
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    stack<int> s;

    // Input elements into queue
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Move elements from queue to stack
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Move elements back to queue (reversed order)
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Print reversed queue
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
