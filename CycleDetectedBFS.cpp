#include <bits/stdc++.h>
using namespace std;

bool cycle(int src, vector<int> &vis, vector<vector<int>> &adj) {
    vis[src] = 1;
    // Store <source node, parent>
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();
        for (auto x : adj[node]) {
            if (!vis[x]) {
                vis[x] = 1;
                q.push({x, node});
            } else if (parent != x) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n = 7;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    /* input 
    0 1 1 0 0 0 0
    1 0 0 0 1 0 0
    1 0 0 1 0 1 0
    0 0 1 0 0 0 0
    0 1 0 0 0 0 1
    0 0 1 0 0 0 1
    0 0 0 0 1 1 0
    */
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (mat[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // Print adj list
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> vis(n + 1, 0);
    bool hasCycle = false; 

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (cycle(i, vis, adj)) {
                hasCycle = true;
                break; 
            }
        }
    }

    if (hasCycle) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
