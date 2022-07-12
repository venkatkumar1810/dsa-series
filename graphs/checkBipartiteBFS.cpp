class Solution {
public:
    bool bipartiteBFS(int src, vector<vector<int>>& adj, int color[]){
        queue<int> q;
        q.push(src);
        color[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                if(color[it] == -1){
                    color[it] = 1 - color[node];
                    q.push(it);
                }else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // unordered_set<int> s;
//         for(int i =0 ; i < edges.size(); i++){
//             s.insert(edges[i][0]);
//             s.insert(edges[i][1]);
//         }

        int n = graph.size();

//         vector<int> adj[n];
//         for(int i=0; i<edges.size(); i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }

        int color[n];
        memset(color, -1, sizeof(color));

        for(int i =0 ; i<n; i++){
            if(color[i] == -1){
                if(!bipartiteBFS(i, graph, color)){
                    return false;
                }
            }
        }

        return true;
    }
};
