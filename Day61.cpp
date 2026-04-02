/*
Problem: Build Graph using Adjacency Matrix

Description:
Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- First line: integer n (number of vertices)
- Second line: integer m (number of edges)
- Next m lines: pairs (u, v) representing edges
- Last line: integer type (0 = undirected, 1 = directed)

Output:
- Print n x n adjacency matrix

Example:
Input:
4
3
0 1
1 2
2 3
0

Output:
0 1 0 0
1 0 1 0
0 1 0 1
0 0 1 0
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
    }

    int type; // 0 = undirected, 1 = directed
    cin >> type;

    if (type == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 1)
                    adj[j][i] = 1;
            }
        }
    }

    // Print matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
