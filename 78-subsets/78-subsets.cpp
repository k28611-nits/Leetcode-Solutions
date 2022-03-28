class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans = {{}};
        for (int a : nums) { 
            int n = ans.size();
            for (int i = 0; i < n; i++) {
                ans.push_back(ans[i]);
                ans.back().push_back(a);
            }
        }
        return ans;
    }
};