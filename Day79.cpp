/*
Problem Statement:
Find shortest distances from source vertex in a weighted graph
with non-negative weights using Dijkstra’s Algorithm.

Input Format:
- First line: n m
  n = number of vertices
  m = number of edges

- Next m lines:
  u v w
  where u-v is an edge with weight w

- Last line:
  source vertex

Output Format:
- Shortest distances from source to all vertices

Sample Input:
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output:
0 2 3 9 6

Explanation:
Shortest distances computed using priority queue.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove for directed graph
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, 1e9);

    // Min-heap: {distance, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        for (auto &neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (d + weight < dist[nextNode]) {
                dist[nextNode] = d + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
