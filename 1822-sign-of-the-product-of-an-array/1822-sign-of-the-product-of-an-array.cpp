class Solution {
public:
    int arraySign(vector<int>& nums) {
        int x=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                x=x*(-1);
            }
            else if(nums[i]>0)
            {
                x=x*1;
            }
            else if(nums[i]==0)
            {
                x=x*0;
            }
        }
        return x;
        
    }
};