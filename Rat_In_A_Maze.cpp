/*
the path that followed by rat to collect the cheese
there are blocked cells and rat can move only in downward 
and sideward direction
maze[][]={{1,0,0,0},
          {1,1,0,1},
          {0,1,0,0},
          {1,1,1,1}}

    NAIVE SOLUTIONS
    traverse all possible pathts and check 
    if that leads to a solution or not

    
*/
#include<bits/stdc++.h>
using namespace std;
#define N 4
bool sol[N][N];
bool solveMazeRec(int i, int j,int maze[][N]);
void printMatrix(bool soln[][4]){
    for(int i =0;i<=N-1;i++){
        for(int j =0;j<N;j++){
            cout<<soln[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solveMaze(int maze[][N]){
    if(solveMazeRec(0,0,maze)==false){
        return false;
    }
    else{
        printMatrix(sol);
        return true;
    }
}

bool isSafe(int i , int j, int maze[][N]){
    return (i<N && j<N && maze[i][j]==1);
}

bool solveMazeRec(int i, int j, int maze[][N]){
    if(i==N-1 && j==N-1){
        sol[i][j]=1;
        return true;
    }
    if(isSafe(i,j,maze)==true){
        sol[i][j]=1;
        if(solveMazeRec(i+1,j,maze)==true) 
            return true;
        else if(solveMazeRec(i,j+1,maze)==true)
            return true;
        else sol[i][j]=0;
    }
    return false;
}

int main(){
    int maze[4][4]={ {1,0,0,0},
              {1,1,0,1},
              {0,1,0,0},
              {1,1,1,1} };

    if(!solveMaze(maze))
        cout<<"NO";
    return 0;
}