class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(2);
        for (int num : nums)
            nums[(num - 1) % 10000] += 10000;
        for (int i = 0; i < N; i++)
            if (nums[i] > 20000) ans[0] = i + 1;
            else if (nums[i] < 10001) ans[1] = i + 1;
        return ans;
    }
};