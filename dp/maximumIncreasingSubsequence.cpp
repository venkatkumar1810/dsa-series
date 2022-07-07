#include<bits/stdc++.h>
int f(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp){
    if(ind == n) return 0;
    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind];
    
    int len = 0 + f(ind + 1, prev_ind, arr, n, dp);
    if(prev_ind == -1 || arr[ind] > arr[prev_ind])
        len = max(len , 1 + f(ind + 1, ind, arr, n, dp));
    
    return dp[ind][prev_ind+1] = len;
}

int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
    // Write Your Code here
//     vector<vector<int>> dp(n, vector<int>(n+ 1, -1));
//     return f(0, -1, arr, n , dp);
    vector<vector<int>> dp(n+1, vector<int>(n+ 1, 0));
    vector<int> curr(n+3, 0), next(n+3, 0);
    for(int ind = n - 1; ind>=0 ; ind--){
        for(int prev_ind = ind - 1; prev_ind >= -1; prev_ind--){
            int len = 0 + next[prev_ind + 2];
            if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
                len = max(len , arr[ind] + next[ind + 2]);
            }
            curr[prev_ind+2] = len;
        }
        next = curr;
    }
    return next[-1+2];
}
