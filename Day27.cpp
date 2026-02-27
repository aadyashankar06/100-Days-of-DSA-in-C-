/*
Problem:
Find intersection point of two linked lists.
If found, print the value.
Else print "No Intersection".
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

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

int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, m;

    cin >> n;
    Node* head1 = createList(n);

    cin >> m;
    Node* head2 = createList(m);

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    Node* temp1 = head1;
    Node* temp2 = head2;

    // Align both lists
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            temp1 = temp1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++)
            temp2 = temp2->next;
    }

    // Traverse together
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data == temp2->data) {
            cout << temp1->data;
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    cout << "No Intersection";

    return 0;
}
