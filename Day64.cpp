/*
Problem: Perform BFS from a given source using queue.

Description:
Perform Breadth First Search (BFS) traversal on a graph starting from a given source node.

Input:
- First line: integer n (number of vertices)
- Next n lines: adjacency list (each line starts with number of neighbors followed by neighbors)
- Last line: source node s

Output:
- Print BFS traversal order

Example:
Input:
5
2 1 2
2 0 3
2 0 4
1 1
1 2
0

Output:
0 1 2 3 4
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    int s;
    cin >> s;

    vector<int> visited(n, 0);
    queue<int> q;

    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return 0;
}
