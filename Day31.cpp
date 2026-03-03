/*
Problem:
Implement Stack using Array with push, pop and display operations.
*/

#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    stackArr[top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << stackArr[top] << endl;
    top--;
}

// Display operation (top to bottom)
void display() {
    if (top == -1) {
        cout << "Stack is Empty" << endl;
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int value;
            cin >> value;
            push(value);
        }
        else if (op == 2) {
            pop();
        }
        else if (op == 3) {
            display();
        }
    }

    return 0;
}
