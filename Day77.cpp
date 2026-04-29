/*
Problem Statement:
Using BFS or DFS, check if the entire graph is connected.

Input Format:
- First line: n m
  n = number of vertices
  m = number of edges

- Next m lines:
  u v (edge between u and v)

Output Format:
- CONNECTED
- NOT CONNECTED

Sample Input:
4 2
1 2
3 4

Sample Output:
NOT CONNECTED
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

    // Start DFS from node 1
    dfs(1, adj, visited);

    // Check if all nodes are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NOT CONNECTED";
            return 0;
        }
    }

    cout << "CONNECTED";

    return 0;
}
