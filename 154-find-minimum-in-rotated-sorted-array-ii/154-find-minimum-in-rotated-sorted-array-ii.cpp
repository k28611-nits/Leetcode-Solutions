class Solution {
public:
    int findMin(vector<int>& nums) {
       int r = nums.size()-1, l = 0, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else if (nums[mid] < nums[r]) r = mid;
            else r--;
        }
        return nums[l];
    }
};