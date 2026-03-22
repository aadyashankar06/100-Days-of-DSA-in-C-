/*
Problem: BST Search

Description:
Search for a given value in a Binary Search Tree (BST).

Input:
- First line contains integer N (number of elements)
- Second line contains N space-separated integers (BST elements)
- Third line contains integer key to search

Output:
- Print "Found" if key exists in BST
- Otherwise print "Not Found"

Example:
Input:
5
10 5 15 3 7
7

Output:
Found
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert into BST (to build tree)
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST
bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int N;
    cin >> N;

    Node* root = NULL;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int key;
    cin >> key;

    if (search(root, key))
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}
