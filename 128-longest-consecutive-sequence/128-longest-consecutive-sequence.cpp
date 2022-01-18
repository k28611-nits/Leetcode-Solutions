class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<1)
            return 0;
        sort(nums.begin(),nums.end());
        long long int ans=1,pd=1;
        for(long long int i=1;i<nums.size();++i)
        {
            if(nums[i]-nums[i-1]==1)
                ans++;
            else if(nums[i]-nums[i-1]==0)
            {
                ans++;
                ans--;
            }
            else
            {
                pd=max(pd,ans);
                ans=1;
            }
        }
        return max(pd,ans);
    }
};