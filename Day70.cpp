/*
Problem:
Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u, v, w)
- source vertex s

Output:
- Shortest distances OR NEGATIVE CYCLE
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int s;
    cin >> s;

    vector<int> dist(n, 1e9);
    dist[s] = 0;

    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (auto [u, v, w] : edges) {
        if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
            cout << "NEGATIVE CYCLE";
            return 0;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
