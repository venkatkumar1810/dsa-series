#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    if(grid[0][0] == 1) return -1;

    queue<vector<int>> q;
    q.push({0,0,1});
    while(!q.empty()){
        int k = q.size();
        while(k--){
            vector<int> curr = q.front();
            q.pop();
            if(curr[0] == m -1 && curr[1] == n -1) return curr[2];
            vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
            for( auto it : dir){
                int r = curr[0] + it[0];
                int c = curr[1] + it[1];
                if( r >= 0 && r< m && c >= 0 && c < n && grid[r][c] == 0){
                    q.push({r,c,curr[2]+1});
                    grid[r][c] = 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> grid ={{0,1,0,0},
                               {0,0,1,0},
                               {0,0,1,0},
                               {0,0,1,0}};
    int steps = bfs(grid);
    cout<<steps<<" ";
    return 0;
}