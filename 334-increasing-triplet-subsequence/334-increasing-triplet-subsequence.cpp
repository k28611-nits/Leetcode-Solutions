class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX,second=INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > second) {
                return true;
            }
            if(nums[i] > first) {
                second = min(second, nums[i]);
            }
            first = min(first, nums[i]);
        }
        return false;
    }
};