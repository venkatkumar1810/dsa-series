#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i =0;i<m;i++){
        int a, b, wt;
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }
    int source;
    cin>>source;
    vector<int> dist(n+1,INT_MAX);
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    dist[source] = 0;
    pq.push(make_pair(0,source));
    while(!pq.empty()){
        int distT = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        for(auto it =  adj[prev].begin() ; it != adj[prev].end() ; it++){
            int next = it->first;
            int wt = it->second;
            if(dist[next] > dist[prev] + wt){
                dist[next] = dist[prev] + wt;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    cout<<"res "<<"\n";
    for(int i =0;i<n;i++) cout<<dist[i]<<" ";
    return 0;
}