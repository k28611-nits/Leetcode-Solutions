class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(temp.size() == 0 || temp.back() < nums[i])
                temp.push_back(nums[i]);
            else{
        
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }
};