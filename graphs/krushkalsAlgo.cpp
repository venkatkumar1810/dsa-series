// #include<bits/stdc++.h>
// struct node{
//     int u;
//     int v;
//     int wt;
//     node(int first, int second, int weight){
//         u = first;
//         v = second;
//         wt = weight;
//     }
// };

// bool comp(node a, node b){
//     return a.wt < b.wt;
// }

// int findPar(int u, vector<int> &parent){
//     if(u == parent[u]) return u;
//     return findPar(parent[u], parent);
// }

// void unionn(int u, int v, vector<int> &parent, vector<int> &rank){
//     u = findPar(u, parent);
//     v = findPar(v, parent);
//     if(rank[u] < rank[v]){
//         parent[u] = v;
//     }else if(rank[v] < rank[u]){
//         parent[v] = u;
//     }else{
//         parent[v] = u;
//         rank[u]++;
//     }
// }

// int kruskalMST(int n, int m, vector<vector<int>> &edges) {
// 	// Write your code here.
//     sort(edges.begin(), edges.end(), comp);
    
//     vector<int> parent(n);
//     for(int i =0; i<n; i++){
//         parent[i] = i;
//     }
//     vector<int> rank(n, 0);
    
//     int cost = 0;
//     vector<pair<int, int>> mst;
//     for(auto it: edges){
//         if(findPar(it.v, parent) != findPar(it.u, parent)){
//             cost += it.wt;
//             mst.push_back({it.u, it.v});
//             unionn(it.u it.v, parent, rank);
//         }
//     }
//     cout<<cost<<endl;
//     for(auto it: mst) cout<<it.first<<"-"<<it.second<<endl;
//     return 0;
// }

#include<algorithm>
bool comp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
int findpar(int u,vector<int>&par){ // DISJOINT SET FIND
    if(u==par[u]) //if reqd node present in set
        return u; // parent found, return parent
    return par[u]= findpar(par[u],par); // recur for parent to find the absolute parent
}

int union_(int u, int v, vector<int> &par){
    if(findpar(u,par)==findpar(v,par))  // if both are part of same set
        return 0;  // union not possible
    else if(!(u>=0 && v>=0 && u<par.size() && v<par.size())) // if anyone is out of bounds 
        return 0; // union not possible
    par[u]=v; //save the better (more accurate) parent
}

int kruskalMST(int n, int m, vector<vector<int>> &edges) {
    sort(edges.begin(),edges.end(),comp); // will iterate greedy
    vector<int> parent(n+1);
    for(int i=0;i<parent.size();i++) 
        parent[i]=i;
    
    int cost=0;
    //vector<pair<int,int>> mst; // incase need mst reqd too? keep storing here
    for(auto it:edges){
        if(findpar(it[0],parent)!=findpar(it[1],parent)){ //if nodes are from diff sets
            cost+=it[2]; // add the cost of the connection
            union_(findpar(it[0],parent),findpar(it[1],parent),parent); // join them
        }
    }
    return cost;
}
