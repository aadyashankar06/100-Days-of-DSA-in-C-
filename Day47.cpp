/*
Problem: Height of Binary Tree

Description:
Find the height (maximum depth) of a given binary tree.

Input:
- First line contains integer N
- Second line contains N space-separated integers (level-order traversal)
- -1 represents NULL

Output:
- Print the height of the binary tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3
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

// Height function
int height(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Node* root = buildTree(arr);

    cout << height(root);

    return 0;
}
