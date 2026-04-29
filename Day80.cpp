/*
Problem:
Given a weighted graph, implement Floyd-Warshall Algorithm
to find shortest distances between every pair of vertices.

Input:
- First line: n (number of vertices)
- Next n lines: adjacency matrix
  (-1 means no direct edge)

Output:
- Shortest distance matrix

Example:
Input:
4
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0

Output:
0 5 8 9
-1 0 3 4
-1 -1 0 1
-1 -1 -1 0
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];

            // Replace -1 with INF (except diagonal)
            if (dist[i][j] == -1 && i != j) {
                dist[i][j] = 1e9;
            }
        }
    }

    // Floyd-Warshall Algorithm
    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][via] != 1e9 &&
                    dist[via][j] != 1e9) {

                    dist[i][j] = min(dist[i][j],
                                     dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    // Print result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == 1e9)
                cout << -1 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
