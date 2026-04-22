/*
Problem:
Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

Input:
- n (vertices)
- m (edges)
- m lines: u v w (edge from u to v with weight w)
- source vertex s

Output:
- Shortest distance from source to all vertices
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove for directed graph
    }

    int s;
    cin >> s;

    vector<int> dist(n, 1e9);
    dist[s] = 0;

    // min-heap {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            if (d + weight < dist[neighbor]) {
                dist[neighbor] = d + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
