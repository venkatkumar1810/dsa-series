class Solution {
public:
    int f(int ind, int buy, int cap, vector<int> &prices, int n, 
         vector<vector<vector<int>>> &dp){
        if(ind == n || cap == 0) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int  profit = 0;
        if(buy == 1){
            profit = max( -prices[ind] + f(ind + 1, 0, cap, prices, n, dp),
                     0 + f(ind, 1, cap, prices, n, dp)); 
        }
            profit = max(prices[ind] + f(ind +1, 1, cap - 1, prices, n, dp),
                                        0 + f(ind + 1, 0, cap, prices, n, dp));
        return dp[ind][buy][cap] = profit;
    }
    
    int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){

        if(ind==n || cap==0) return 0; //base case

        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];

        int profit;

        if(buy==0){// We can buy the stock
            profit = max(0+getAns(Arr,n,ind+1,0,cap,dp), 
                        -Arr[ind] + getAns(Arr,n,ind+1,1,cap,dp));
        }

        if(buy==1){// We can sell the stock
            profit = max(0+getAns(Arr,n,ind+1,1,cap,dp),
                        Arr[ind] + getAns(Arr,n,ind+1,0,cap-1,dp));
        }

        return dp[ind][buy][cap] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));
        
        return getAns(prices,n,0,0,2,dp);
    }
};
