/*
Problem:
Merge two sorted linked lists using dynamic memory allocation.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create linked list
Node* createList(int n) {
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
    return head;
}

// Merge two sorted lists
Node* mergeLists(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;
}

int main() {
    int n, m;

    cin >> n;
    Node* list1 = createList(n);

    cin >> m;
    Node* list2 = createList(m);

    Node* merged = mergeLists(list1, list2);

    // Print merged list
    Node* temp = merged;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
