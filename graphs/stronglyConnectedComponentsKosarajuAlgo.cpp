#include<bits/stdc++.h>
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, st, vis, adj);
        }
    }
    st.push(node);
}
void revDfs(int node, vector<int> &vis,vector<int> &temp, vector<int> transpose[]){
//     cout<<node<<" ";
    temp.push_back(node);
    vis[node] = 1;
    for(auto it: transpose[node]){
        if(!vis[it]){
            revDfs(it, vis,temp, transpose);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    stack<int> st;
    
    for(int i =0 ; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    vector<int> vis(n, 0);
    for(int i =0; i<n; i++){
        if(!vis[i]){
            dfs(i, st, vis, adj);
        }
    }
    
    vector<vector<int>> res;
    vector<int> transpose[n];
    for(int i =0; i < n; i++){
        vis[i] = 0;
        for(auto it: adj[i]){
            transpose[it].push_back(i);
        }
    }
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        vector<int> temp;
        if(!vis[node]){
            revDfs(node, vis,temp, transpose);
        }
        sort(temp.begin(), temp.end());
        res.push_back(temp);
    }
    
    return res;
}
