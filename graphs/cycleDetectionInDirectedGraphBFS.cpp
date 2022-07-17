#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int V, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> adj[V+1];
    vector<int> vis(V+1,0);
    for(int i=0; i<edges.size(); i++){
        adj[edges[i].first].push_back(edges[i].second);
//         adj[edges[i].second].push_back(edges[i].first);
    }
    
    queue<int> q;
    vector<int> inDegree(V+1, 0);
    for(int i =1 ; i<= V; i++){
        for( auto it: adj[i]){
            inDegree[it]++;
        }
    }
    
    for(int i =1 ; i <= V; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it: adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                q.push(it);
            }
        }
    }
//     cout<<cnt<<" "<<V<<"\n";
    if(cnt == V) return false;
    return true;
}
