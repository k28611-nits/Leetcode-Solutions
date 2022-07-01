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
        
        vector<int> temp1,temp2;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();++i)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        vector<int> dp(temp1.size(),-1);
        int left=find(temp1.size()-1,temp1,dp);
        vector<int> pd(temp2.size(),-1);
        int right=find(temp2.size()-1,temp2,pd);
        return max(right,left);
    }
};