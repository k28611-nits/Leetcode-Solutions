class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
         int ans = 0;
        for (int customer = 0; customer < accounts.size (); customer++) {
            ans = max (ans, accumulate (accounts[customer].begin(),accounts[customer].end () ,0));
        }
        return ans;
    }
};