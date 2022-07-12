#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int N, int E)  {
    // Write your code here
    vector<int> adj[N];
    for(int i=0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    queue<int> q;
    vector<int> inDegree(N, 0);
    for(int i =0 ; i < N; i++){
        for(auto it: adj[i]){
            inDegree[it]++;
        }
    }
    
    for(int i =0 ; i < N; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                q.push(it);
            }
        }
    }
    return topo;
}
