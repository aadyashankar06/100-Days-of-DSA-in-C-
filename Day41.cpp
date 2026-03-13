#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        cout << -1 << endl;
        return;
    }

    Node* temp = front;
    cout << temp->data << endl;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

int main() {

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {

        string op;
        cin >> op;

        if(op == "enqueue") {
            int x;
            cin >> x;
            enqueue(x);
        }
        else if(op == "dequeue") {
            dequeue();
        }
    }

    return 0;
}
