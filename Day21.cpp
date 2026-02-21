/*
Problem:
Create and traverse a singly linked list.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print all elements of the linked list
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

    Node* head = NULL;
    Node* tail = NULL;

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

    // Traverse and print
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
