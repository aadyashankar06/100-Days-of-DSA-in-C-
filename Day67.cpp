/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

Description:
Given a directed acyclic graph (DAG), print its topological ordering using DFS.

Input:
- First line: integer n (number of vertices)
- Second line: integer m (number of edges)
- Next m lines: pairs (u, v) representing directed edges (u → v)

Output:
- Print topological ordering of the graph

Example:
Input:
6
6
5 2
5 0
4 0
4 1
2 3
3 1

Output:
5 4 2 3 1 0
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st) {
    visited[node] = 1;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }

    st.push(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed edge
    }

    vector<int> visited(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    // Print topological order
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
