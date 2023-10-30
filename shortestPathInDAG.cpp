#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void addEdge(int u,int v,int weight){
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
    vector<int> sortedKeys;
    for (auto i : adj) {
        sortedKeys.push_back(i.first);
    }
    sort(sortedKeys.begin(), sortedKeys.end());

    for (int u : sortedKeys) {
        cout << u << "->";
        for (auto j : adj[u]) {
            cout << "(" << j.first << "," << j.second << ") ";
        }
        cout << endl;
    }
}


    void dfs(int node,stack<int> &s,unordered_map<int,bool>& visited){
        visited[node]=true;
        for(auto it : adj[node]){
            if(!visited[it.first]){
                dfs(it.first,s,visited);
            }
        }
        s.push(node);
    }


    void getShortestPath(int src,vector<int> &dist,stack<int>&st){
        dist[src]=0;

    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(dist[top]!=INT_MAX){
            for(auto i : adj[top]){
                if(dist[top]+i.second<dist[i.first]){
                    dist[i.first]=dist[top]+i.second;
                }
            }
        }
    }
    }


};
int main(){
    graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    g.printAdj();

    // topological sort 
    int n=6;
    unordered_map<int,bool> visited;
    stack<int> s;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,s,visited);
        }

    }

    int src=1;
    vector<int> dist(n);

    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;

    }

    g.getShortestPath(src,dist,s);

    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }cout<<endl;
    
   



}