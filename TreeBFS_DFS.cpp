#include<bits/stdc++.h>
using namespace std;

void bfs(int node , vector<int> &vis, vector<int> adj[]){
    cout<<node<<" ";
    vis[node] = 1;
    queue<vector<int>> q;
    q.push(adj[node]);
    while(!q.empty()){
        vector<int> curr = q.front();
        q.pop();
        for(auto it: curr){
            if(!vis[it]){
                cout<<it<<" ";
                vis[it] = 1;
                q.push(adj[it]);
            }
        }
    }
}


void dfs(int node, int par, vector<int> adj[]){
    cout<<node<<" ";
    for(auto it: adj[node]){
        if(it != par){
            dfs(it,node, adj);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i = 0;i<n-1;i++){
        int a, b;
        cin>> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n+1,0);
    cout<<endl;
    bfs(0,vis,adj);
    cout<<endl;
    dfs(0,-1,adj);
    return 0;
}
