/*
    generate all N2 C N possible configurations
    
    NAIVE SOLUTION
    generate all posible permuations of row numbers

*/

#include<bits/stdc++.h>
using namespace std;
#define N 4
bool board[N][N];
bool solveRec(int col);

void printMatrix(){
    for(int i =0;i<=N-1;i++){
        for(int j =0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solve(){
    if(solveRec(0)==false) return false;
    else{
        printMatrix();
        return true;
    }
}
bool isSafe(int row, int col){
    for(int i =0;i<col;i++){
        if(board[row][i]) return false;
    }
    for(int i =row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]) return false;
    }
    for(int i=row,j=col;j>=0 && i<N;i++,j--){
        if(board[i][j]) return false;
    }
    return true;
}

bool solveRec(int col){
    if(col==N) return true;
    for(int i=0;i<N;i++){
        if(isSafe(i,col)){
            board[i][col]=1;
            if(solveRec(col+1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main(){
    // board[4][4]={ {0,0,0,0},
    //           {0,0,0,0},
    //           {0,0,0,0},
    //           {0,0,0,0} };

    if(!solve())
        cout<<"NO";
    return 0;
}