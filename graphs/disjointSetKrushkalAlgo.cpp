#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int parent[100];
int rankk[100];
int size[100];

int findPar(int node){
    if(node == parent[node]) return node;
    return parent[node] = findPar(parent[node]);
}

void unionByRank(int u, int v){
    u = findPar(u);
    v = findPar(v);
    
    if( u == v) return;

    if( rankk[u] < rankk[v]){
        parent[u] = v;
    }else if( rankk[v] < rankk[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rankk[u]++;
    }
}

void unionBySize(int u, int v){
    u = findPar(u);
    v = findPar(v);

    if( u == v ) return;

    if(size[u] < size[v]){
        parent[u] = v;
        size[v] += size[u];
    }else{
        parent[v] = u;
        size[u] += size[v];
    }
}


void init(int n){
    for(int i =1; i<=n;i++){
        parent[i] = i;
        rankk[i] = 0;
    }
}

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.first < b.first;
}

void krushkalAlgo(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, pair<int, int>>> edges;
    for(int i =0 ; i <m; i++){
        int wt, u, v;
        cin>>wt>> u>> v;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());
    init(n);
    
    int costMst = 0;
    vector<pair<int, pair<int, int>>> mst;
    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
    
        if(findPar(u) != findPar(v)){
            costMst += wt;
            unionByRank(u, v);
            mst.push_back({wt, {u, v}});
        }
    }
    
    for(auto it: mst){
        cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
    }
    cout<<costMst<<endl;
}


int main() {
    krushkalAlgo();
    return 0;
}
