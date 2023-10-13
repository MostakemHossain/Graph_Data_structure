#include <bits/stdc++.h>
using namespace std;

void bfsInGraph(vector<int> adj[], int v)
{
    vector<int> vis(v, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
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

    int v = 10;
    vector<int> adj[v + 1];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 7);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 7, 8);
    addEdge(adj, 7, 10);
    addEdge(adj, 8, 9);
    bfsInGraph(adj, v);
}