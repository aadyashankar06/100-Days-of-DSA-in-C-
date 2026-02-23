/*
Problem:
Create a singly linked list and count the number of nodes.
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

    // Traverse and count nodes
    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }

    // (Optional) count is stored if teacher asks
    // cout << "\nTotal Nodes = " << count;

    return 0;
}
