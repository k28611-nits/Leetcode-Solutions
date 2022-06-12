class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = size(nums), cur_sum = 0, ans = 0, l = 0, r = 0;
	unordered_set<int> s;
	while(r < n) {
		while(s.find(nums[r]) != end(s))          // delete from current sub-array till there's a duplicate of nums[r]
			cur_sum -= nums[l], s.erase(nums[l++]);
		cur_sum += nums[r], s.insert(nums[r++]);  // pick nums[r] and update cur_sum
		ans = max(ans, cur_sum);                  // finally update ans to hold the maximum of all subarray sums till now
	}
	return ans;
    }
};