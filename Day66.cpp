/*
Problem:
Detect cycle in directed graph using DFS and recursion stack.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- YES if cycle exists, otherwise NO
*/

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = false; // backtrack
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); // directed graph
    }

    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}
