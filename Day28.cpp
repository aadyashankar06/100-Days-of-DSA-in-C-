/*
Problem:
Create a Circular Linked List and traverse it.
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

    if (n <= 0) return 0;

    Node* head = NULL;
    Node* tail = NULL;

    // Create Circular Linked List
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

    // Make it circular
    tail->next = head;

    // Traverse Circular Linked List
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    return 0;
}
