/*
Problem:
Represent a polynomial using linked list and print it
in standard mathematical format.
*/

#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    // Create polynomial linked list
    for (int i = 0; i < n; i++) {
        int c, e;
        cin >> c >> e;

        Node* newNode = new Node();
        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print polynomial
    Node* temp = head;

    while (temp != NULL) {

        if (temp->exp == 0) {
            cout << temp->coeff;
        }
        else if (temp->exp == 1) {
            cout << temp->coeff << "x";
        }
        else {
            cout << temp->coeff << "x^" << temp->exp;
        }

        if (temp->next != NULL)
            cout << " + ";

        temp = temp->next;
    }

    return 0;
}
