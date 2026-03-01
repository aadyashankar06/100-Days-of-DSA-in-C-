/*
Problem:
Rotate Linked List Right by k Places
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    if (n == 0) return 0;

    Node* head = NULL;
    Node* tail = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    cin >> k;

    k = k % n;  // Important when k > n
    if (k == 0) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        return 0;
    }

    // Make list circular
    tail->next = head;

    // Find new tail: (n - k)th node
    int steps = n - k;
    Node* temp = head;

    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // New head
    head = temp->next;

    // Break circular link
    temp->next = NULL;

    // Print rotated list
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
