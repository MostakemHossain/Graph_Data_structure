#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<vector<int> >& adjList) {
    vis[node] = 1;
    for (auto it : adjList[node]) {
        if (!vis[it]) {
            dfs(it, vis, adjList);
        }
    }
}

int numberOfProvinces(vector<vector<int> >& adj, int V) {
    vector<vector<int> > adjList(V, vector<int>());
    // To change the adj matrix to list
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    vector<int> vis(V, 0);
    int cnt = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i, vis, adjList);
        }
    }
    return cnt;
}

int main() {
    vector<vector<int> > adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    int n = numberOfProvinces(adj, 3);
    cout << n << endl;
}
