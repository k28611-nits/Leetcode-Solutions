class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1000000000 + 7;
        sort(nums.begin(), nums.end());
        int n_ways = 0, base = 1;
        int start, end;
        auto it = upper_bound(nums.begin(), nums.end(), target/2);
        start = it - nums.begin();
        if (start == 0) {
            return 0;
        }
        start--;
        end = start;
        while (start >= 0) {
            while (end != nums.size() - 1 && nums[start] + nums[end+1] <= target) {
                end++;
                base = (long long)base * 2 % mod;
            }
            n_ways = ((long long) n_ways + base) % mod;
            start--;
            base = (long long)base * 2 % mod;
        }
        return n_ways;
    }
};