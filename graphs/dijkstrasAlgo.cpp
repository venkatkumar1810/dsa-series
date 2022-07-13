#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int n, int m, int source) {
    // Write your code here.
    vector<pair<int, int>> g[n + 1];
    for(int i = 0; i<m; i++){
        int a = vec[i][0];
        int b = vec[i][1];
        int wt = vec[i][2];
        g[a].push_back(make_pair(b, wt));
        g[b].push_back(make_pair(a, wt));
    }
    
    priority_queue< pair<int, int> , vector<pair<int, int>> , greater< pair<int, int>> > pq;
    vector<int> distTo(n, INT_MAX);
    
    distTo[source] = 0;
    pq.push(make_pair(0, source));
    
    while( !pq.empty() ){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        
        vector< pair<int, int> >::iterator it;
        for(it = g[prev].begin(); it != g[prev].end(); it++){
            int next = it->first;
            int nextDist = it->second;
            if( distTo[next] > distTo[prev] + nextDist){
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
    return distTo;
}
