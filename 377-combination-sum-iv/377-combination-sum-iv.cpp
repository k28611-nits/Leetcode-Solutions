class Solution {
public:
    int combination(vector<int>& nums, int target,int total,vector<int>&dp)
{
    if(target==total)
        return 1;
    if(dp[total]!=-1)
        return dp[total];
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
        if(total+nums[i]<=target)
            ans+=combination(nums,target,total+nums[i],dp);
    }
    return dp[total]=ans;
}

int combinationSum4(vector<int>& nums, int target) {
    vector<int>dp(target+1,-1);
    int count=combination(nums,target,0,dp);
    return count;
    
}
};