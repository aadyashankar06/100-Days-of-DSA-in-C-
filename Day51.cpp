/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6
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

// Find LCA in BST
Node* LCA(Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (p < root->data && q < root->data)
        return LCA(root->left, p, q);

    if (p > root->data && q > root->data)
        return LCA(root->right, p, q);

    return root; // split point
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

    int p, q;
    cin >> p >> q;

    Node* ans = LCA(root, p, q);

    if (ans)
        cout << ans->data;

    return 0;
}
