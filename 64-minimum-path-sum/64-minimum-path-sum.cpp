class Solution {
public:
    
    int f(int row,int col, vector<vector<int>> &dp,vector<vector<int>>& grid)
    {
        if(row==0 and col==0)
            return grid[0][0];
        if(row<0 or col<0) return 1000;
        if(dp[row][col]!=-1) return dp[row][col];
        int up=grid[row][col]+f(row-1,col,dp,grid);
        int left=grid[row][col]+f(row,col-1,dp,grid);
        return dp[row][col]=min(up,left);
        
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,grid);
    }
};