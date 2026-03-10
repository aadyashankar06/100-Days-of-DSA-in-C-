#include <iostream>
using namespace std;

#define MAX 100

int cq[MAX];
int front = -1, rear = -1;
int size = MAX;

void enqueue(int x) {
    if ((rear + 1) % size == front) {
        cout << "Queue Overflow";
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % size;
    }

    cq[rear] = x;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow";
        return;
    }

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % size;
    }
}

void display() {
    if (front == -1) return;

    int i = front;

    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % size;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        enqueue(x);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}
