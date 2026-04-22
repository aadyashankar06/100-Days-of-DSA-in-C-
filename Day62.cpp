/*
Problem:
Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // remove for directed graph
    }

    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
