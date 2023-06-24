class Solution {
public:
    int solve(int i, int prev, vector<int>& nums, unordered_map<int, vector<int>> &mp, vector<vector<int>> &DP){
        if(i >= nums.size()) return 0;
        if(DP[i][prev] != -1) return DP[i][prev];

        int ans = 0;
        int target = (2*nums[i]) - nums[prev];

        if(mp.find(target) != mp.end()){
            int idx = upper_bound(mp[target].begin(), mp[target].end(), i) - mp[target].begin();

            if(idx < mp[target].size()){
                idx = mp[target][idx];
                ans = 1 + solve(idx, i, nums, mp, DP);
            }
        }

        return DP[i][prev] = ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int ans = 0;

        unordered_map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        vector<vector<int>> DP(nums.size(), vector<int>(nums.size(), -1));
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                ans = max(ans, 2 + solve(j, i, nums, mp, DP));
            }
        }

        return ans;
    }
};