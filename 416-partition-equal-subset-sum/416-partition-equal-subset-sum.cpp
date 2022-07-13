class Solution {
public:
    bool f(int ind,int target,vector<int>& nums,vector<vector<int>>& dp )
    {
        if(ind<=0 or target<=0) return target==0 ;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool nottake=f(ind-1,target,nums,dp);
        bool take=false;
        if(target>=nums[ind]) take=f(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]= take or nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(sum%2==0)
        {
            vector<vector<int>> dp(201,vector<int>(20001,-1));
            return f(n-1,sum/2,nums,dp);
        } 
        else
            return false;
    }
};