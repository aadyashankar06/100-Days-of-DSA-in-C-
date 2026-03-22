/*
Problem: BST Insert

Description:
Insert elements into a Binary Search Tree (BST) and print its inorder traversal.

Input:
- First line contains integer N (number of elements)
- Second line contains N space-separated integers

Output:
- Print inorder traversal of the BST

Example:
Input:
5
10 5 15 3 7

Output:
3 5 7 10 15

Explanation:
Insert elements into BST and print inorder (sorted order).
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

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder traversal (sorted order)
void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    inorder(root);

    return 0;
}
