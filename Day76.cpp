/*
Problem Statement:
Using DFS or BFS, count number of connected components.

Input Format:
- First line: n m
  where n = number of vertices
        m = number of edges

- Next m lines:
  u v (edge between u and v)

Output Format:
- Number of connected components

Sample Input:
6 3
1 2
2 3
5 6

Sample Output:
3

Explanation:
Components are:
{1,2,3}, {4}, {5,6}
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    vector<bool> visited(n + 1, false);

    int components = 0;

    // Check all nodes
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    cout << components;

    return 0;
}
