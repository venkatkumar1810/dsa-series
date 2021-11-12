#include<bits/stdc++.h>
using namespace std;

int mindice(vector<int> &moves, int n){
    vector<int> vis(n,0);

    queue<vector<int>>  q;

    vis[0] = 1;
    q.push({0,0});

    while(!q.empty()){
        vector<int> curr = q.front();
        q.pop();

        int vert = curr[0];
        if(vert == n-1)  return curr[1];

        for(int j = vert +1; j<= vert+6 && j<n; j++){
            if(!vis[j]){
                vis[j] = 1;
                vector<int> temp;
                if(moves[j] != -1){
                    temp = {moves[j], curr[1] +1};
                }else{
                    temp = {j, curr[1] +1};
                }
                q.push(temp);
            }
        }
    }
    return -1;
}

int main(){
    int n = 100;
    vector<int> moves(n,-1);
    
    // ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[16] = 95;
    moves[40] = 99;

    // snakes
    moves[55] = 15;
    moves[65] = 39;
    moves[90] = 13;
    moves[31] = 10;

    cout<< " min throws : \n" << mindice(moves, n);
    return 0;
}