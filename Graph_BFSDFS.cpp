#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<int> &vis, vector<int> adj[]){
    cout<<node<<" ";
    vis[node] = 1;
    queue<vector<int>> q;
    q.push(adj[node]);
    while(!q.empty()){
        vector<int> curr = q.front();
        q.pop();
        for(auto it: curr){
            if(!vis[it]){
                vis[it] = 1;
                cout<<it<<" ";
                q.push(adj[it]);
            }
        }
    }
}

void dfs(int node, vector<int> &vis, vector<int> adj[]){
    cout<<node<<" ";
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj);
        }
    }
}

int main(){
    int n , m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0;i<m;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n+1,0);
    bfs(0,vis,adj);
    cout<<endl;
    vis = vector<int>(n+1,0);
    dfs(0,vis,adj);
    return 0;
}