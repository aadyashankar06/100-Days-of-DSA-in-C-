/*
Problem:
Implement push and pop operations on a stack and
print remaining elements from top to bottom.
*/

#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow";
        return;
    }
    stackArr[++top] = x;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow";
        return;
    }
    top--;
}

int main() {
    int n;
    cin >> n;

    // Push elements
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push(x);
    }

    int m;
    cin >> m;

    // Pop elements
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display stack (top to bottom)
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }

    return 0;
}
