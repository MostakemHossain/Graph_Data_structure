#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<vector<int>> &adj) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printG(vector<vector<int>> &adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << "-> ";
        sort(adj[i].begin(), adj[i].end()); // Sort the adjacency list for vertex i

        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, adj);
    }

    printG(adj);
    return 0;
}
