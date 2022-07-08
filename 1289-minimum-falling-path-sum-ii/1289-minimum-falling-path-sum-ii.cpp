class Solution {
public:
    int fun(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&dp){
        if(i == grid.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans =  INT_MAX;
        for(int k = 0; k < grid[0].size(); k++){
            if(j == k)
                continue;
            ans = min(ans, fun(grid,i + 1, k, dp) + grid[i][j]);
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int n = grid.size();
        if(n == 1)
            return grid[0][0];
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int ans = INT_MAX;
        for(int j = 0; j < n; j++)
            ans = min(ans, fun(grid, 0, j, dp));
        return ans;
    }
};