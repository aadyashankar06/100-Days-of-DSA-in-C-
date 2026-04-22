/*
Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1
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

// Build tree function
Node* buildTree(vector<int>& preorder, int preStart, int preEnd,
                vector<int>& inorder, int inStart, int inEnd,
                unordered_map<int, int>& mp) {
    
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];
    Node* root = new Node(rootVal);

    int inRoot = mp[rootVal];
    int leftSize = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + leftSize,
                           inorder, inStart, inRoot - 1, mp);

    root->right = buildTree(preorder, preStart + leftSize + 1, preEnd,
                            inorder, inRoot + 1, inEnd, mp);

    return root;
}

// Postorder traversal
void postorder(Node* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int N;
    cin >> N;

    vector<int> preorder(N), inorder(N);

    for (int i = 0; i < N; i++)
        cin >> preorder[i];

    for (int i = 0; i < N; i++)
        cin >> inorder[i];

    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
        mp[inorder[i]] = i;

    Node* root = buildTree(preorder, 0, N - 1, inorder, 0, N - 1, mp);

    postorder(root);

    return 0;
}
