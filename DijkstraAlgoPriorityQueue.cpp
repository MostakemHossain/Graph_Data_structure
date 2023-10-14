#include <bits/stdc++.h>
using namespace std;

 vector<int>dijkstra(vector<vector<int>> adj[],int S,int V){

    //Create a prority Queue for Sorting the nodes as a pair {dist,nodes};
    //where dist is the distance from the node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(V, INT_MAX);

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
    
                    // If current distance is smaller,
                    // push it into the queue.
                    pq.push({dis + w, v});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return distTo;
 }


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V=3,E=3,S=2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1,1},v2{2,6},v3{2,3},v4{0,1},v5{1,3},v6{0,6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);
    vector<int>res=dijkstra(adj,S,V);

    for(int it=0;it<V;it++){
        cout<<res[it]<<" ";
    }cout<<endl;


  
}
