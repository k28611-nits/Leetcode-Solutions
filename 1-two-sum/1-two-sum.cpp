class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();++i)
        {
            if(hash.find(target-nums[i])!=hash.end())
            {
                return{i,hash[target-nums[i]]};
            }
            hash[nums[i]]=i;
        }
        return {};
    }
};