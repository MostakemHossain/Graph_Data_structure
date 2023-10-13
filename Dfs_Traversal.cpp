#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    // traversal all neighbour
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

void dfsOnGraph(vector<int> adj[], int v)
{
    vector<int> vis(v, 0);
    int start = 1;
    vector<int> ls;
    dfs(start, adj, vis, ls);

    for (int i = 0; i < ls.size(); i++)
    {
        cout << ls[i] << " ";
    }
    cout << endl;
}

void addEdge(vector<int> adj[], int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}
int main()
{
    vector<int> adj[10 + 1];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 7);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 7, 8);
    addEdge(adj, 7, 10);
    addEdge(adj, 8, 9);
    dfsOnGraph(adj, 10);
}