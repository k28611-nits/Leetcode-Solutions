class Solution {
public:
    int find(int index, vector<int>& nums, vector<int>& dp)
    {
        int pick,notpick;
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        pick=nums[index] + find(index-2,nums,dp);
        notpick=find(index-1,nums,dp);
        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
       vector<int> dp(nums.size(),-1);
        return find(nums.size()-1,nums,dp);
    }
};