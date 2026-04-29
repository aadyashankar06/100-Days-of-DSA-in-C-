/*
Problem Statement:
Given a weighted undirected graph, compute the total weight
of the Minimum Spanning Tree (MST) using Prim’s Algorithm.

Input Format:
- First line: n m
  n = number of vertices
  m = number of edges

- Next m lines:
  u v w
  where u-v is an edge with weight w

Output Format:
- Total weight of MST

Sample Input:
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output:
6

Explanation:
MST edges:
(2-3) = 1
(3-4) = 2
(1-2) = 3
Total = 6
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    // Input graph
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Min-heap: {weight, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<bool> visited(n + 1, false);

    int mstWeight = 0;

    // Start from node 1
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        mstWeight += weight;

        for (auto &neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!visited[nextNode]) {
                pq.push({edgeWeight, nextNode});
            }
        }
    }

    cout << mstWeight;

    return 0;
}
