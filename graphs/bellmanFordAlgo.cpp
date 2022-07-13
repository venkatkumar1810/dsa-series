#include<bits/stdc++.h>
struct node{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

int bellmonFord(int N, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<node> edges;
    for(int i= 0; i < m; i++){
        edges.push_back(node(edges[i][0], edges[i][1], edges[i][2]));
    }
    
    int inf = 1000000000;
    vector<int> dist(N+1, inf);
    
    dist[src] = 0;
    
    for(int i = 1; i<=N-1; i++){
        for(auto it: edges){
            if(dist[it.u] + it.wt < dist[it.v]){
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    
    int fl = 0;
    for(auto it: edges){
        if(dist[it.u] + it.wt < dist[it.v]){
            cout<<"Neg Cycle";
            fl = 1;
            break;
        }
    }
    
    if(fl == 0){
        for(int i = 1; i<=N; i++){
            cout<<i<<" "<<dist[i]<<endl;
        }
    }
    return dist[dest];
}

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> distance(n+1, 1e9);
    distance[src] = 0;

    for(int i=0; i<n-1; i++) {
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            int W = distance[u] == 1e9 ? 1e9 : w + distance[u];

            distance[v] = min(distance[v], W);
        }
    }

    return distance[dest];

}
