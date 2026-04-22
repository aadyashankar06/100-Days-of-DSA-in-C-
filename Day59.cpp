/*
Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3
*/

#include <iostream>
#include <vector>
#include <unordered_map>
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

Node* buildTree(vector<int>& inorder, int inStart, int inEnd,
                vector<int>& postorder, int postStart, int postEnd,
                unordered_map<int, int>& mp) {
    
    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    int rootVal = postorder[postEnd];
    Node* root = new Node(rootVal);

    int inRoot = mp[rootVal];
    int leftSize = inRoot - inStart;

    root->left = buildTree(inorder, inStart, inRoot - 1,
                           postorder, postStart, postStart + leftSize - 1, mp);

    root->right = buildTree(inorder, inRoot + 1, inEnd,
                            postorder, postStart + leftSize, postEnd - 1, mp);

    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;
    cin >> N;

    vector<int> inorder(N), postorder(N);

    for (int i = 0; i < N; i++)
        cin >> inorder[i];

    for (int i = 0; i < N; i++)
        cin >> postorder[i];

    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
        mp[inorder[i]] = i;

    Node* root = buildTree(inorder, 0, N - 1,
                           postorder, 0, N - 1, mp);

    preorder(root);

    return 0;
}
