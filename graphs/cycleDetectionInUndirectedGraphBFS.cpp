#include<bits/stdc++.h>
bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited){
    queue<pair<int, int>> q;
    visited[s] = true;
    q.push({s, -1});
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push({it, node});
            }else if(par != it){
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int V, int E)
{
    // Write your code here.
    vector<int> adj[V+1];
    vector<int> vis(V+1,0);
    vector<vector<int>> ans;
    for(int i=0; i<E; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i = 1; i <= V; i++){
        if(!vis[i]){
            if(checkForCycle(i, V, adj, vis)) return "Yes";
        }
    }
    return "No";
}
