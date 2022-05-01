#include<bits/stdc++.h>
using namespace std;


vector<int> kahnsTopo(vector<int> *adjList, int nodes, int edges, vector<int> &inDegree){

    queue<int> q;
    for(int i = 0;i<nodes;i++){
        if(inDegree[i] == 0) q.push(i);
    }

    int count = 0;
    vector<int> res;
    while(!q.empty()){
        int currentNode = q.front();
        res.push_back(currentNode);
        q.pop();
        count++;

        for(auto it: adjList[currentNode]){
            if(--inDegree[it] == 0){
                q.push(it);
            }
        }
    }
    if(count == nodes) return res;
    return {};
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;

    vector<int> inDegree(nodes, 0);
    vector<int> adjList[nodes];

    for(int i = 0 ;i<edges;i++){
        int u, v;
        cin>>u>>v;
        adjList[v].push_back(u);
        inDegree[u]++;
    }    

    vector<int> topoSort = kahnsTopo(adjList, nodes, edges, inDegree);

    for(auto it: topoSort) cout<<it<<" ";

    return 0;
}
// 4 4
// 1 0
// 2 0
// 3 1
// 3 2
// 0 1 2 3 