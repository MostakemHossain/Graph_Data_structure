#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], vector<vector<int>>& adjList) {
    vis[node] = 1;
    for (auto it : adjList[node]) {
        if (!vis[it]) {
            dfs(it, vis, adjList);
        }
    }
}

int main() {
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    vector<vector<int>> adjList(3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (adj[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
            }
        }
    }

    int vis[3] = {0};
    int c = 0;
    for (int i = 0; i < 3; i++) {
        if (!vis[i]) {
            c++;
            dfs(i, vis, adjList);
        }
    }
    cout << c << endl;
}
