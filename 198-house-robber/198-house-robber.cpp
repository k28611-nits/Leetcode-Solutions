class Solution {
public:
    int f(int n,vector<int>& nums, vector<int>&dp)
    {
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+f(n-2,nums,dp);
        int notpick=f(n-1,nums,dp);
        return dp[n]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return f(nums.size()-1,nums,dp);
    }
};