/*
Problem Statement:
Level Order Traversal of a Binary Tree

Given a binary tree, print its level order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (level-order traversal)
- -1 represents NULL

Output Format:
- Print elements level by level from left to right

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 2 3 4 5 6 7

Explanation:
Traverse the tree level by level using a queue.
*/

#include <iostream>
#include <queue>
#include <vector>
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

// Build tree from level order
Node* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1)
        return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i >= arr.size()) break;

        if (arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Level Order Traversal (BFS)
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Node* root = buildTree(arr);

    levelOrder(root);

    return 0;
}
