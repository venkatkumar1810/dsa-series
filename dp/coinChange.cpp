#include<bits/stdc++.h>
long f(int ind , int T, int * a, vector<vector<long>> &dp){
    if(ind == 0){
        return (T % a[0] == 0);
    }
    if(dp[ind][T] != -1) return dp[ind][T];
    
    long notTake = f(ind - 1, T, a, dp);
    long take = 0;
    if(a[ind] <= T) take = f(ind, T - a[ind], a, dp);
    
    return dp[ind][T] = take + notTake;
}
long countWaysToMakeChange(int *a, int n, int value)
{
    //Write your code here
//     vector<vector<long>> dp(n, vector<long>(value +1 , -1));
    
    vector<vector<long>> dp(n+1, vector<long>(value +1 , 0));
    for(int T = 0; T <= value; T++){
        dp[0][T] = (T % a[0] == 0);
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= value; T++){
            long notTake = dp[ind - 1][T];
            long take = 0;
            if(a[ind] <= T) take = dp[ind][T - a[ind]];
            dp[ind][T] = take + notTake;
        }
    }
    return dp[n - 1][value];
}
