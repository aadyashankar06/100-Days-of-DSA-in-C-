/*
Problem:
Implement topological sorting using in-degree array and queue (Kahn’s Algorithm).

Input:
- n (vertices)
- m (edges)
- m pairs (u, v) meaning u → v

Output:
- Topological order of vertices
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If topo size != n → cycle exists
    if (topo.size() != n) {
        cout << "Cycle exists, no topological ordering possible";
    } else {
        for (int x : topo) {
            cout << x << " ";
        }
    }

    return 0;
}
