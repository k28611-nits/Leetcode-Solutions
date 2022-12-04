class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long md = INT_MAX, ans = -1;
        vector<long long> prefix(n, 0);
        for (int i = 0; i < n; i++)
            prefix[i] = nums[i] + ((i == 0) ? 0 : prefix[i - 1]);
        for (int i = 0; i < n; i++)
        {
            long long s1 = prefix[i], s2 = prefix[n - 1] - prefix[i];
            long long d = abs(s1 / (long long)(i + 1) - ((i == n - 1) ? 0 : s2 / (long long)(n - i - 1)));
            if (d < md)
            {
                ans = i;
                md = d;
            }
        }
        return ans;
    } 
};