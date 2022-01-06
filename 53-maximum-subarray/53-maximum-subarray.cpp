class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int n=nums.size(), sum=INT_MIN, temp=0;        
        
        for(int i=0;i<n;i++)
        {
            temp=max(nums[i],nums[i]+temp);
            sum=max(sum,temp);
        }
        return sum;
    }
};