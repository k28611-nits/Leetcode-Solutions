class Solution {
public:
    int f(int ind, int target,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(ind==0) return (target%coins[ind]==0);
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake=f(ind-1,target,coins,dp);
        int take=0;
        if(target>=coins[ind]) take=f(ind,target-coins[ind],coins,dp);
        return dp[ind][target]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return f(coins.size()-1,amount,coins,dp);
    }
};