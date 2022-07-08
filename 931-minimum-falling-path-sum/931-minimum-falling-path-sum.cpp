class Solution {
public:
    int f(int row,int col, vector<vector<int>> &matrix,vector<vector<int>>& dp,int n)
    {
        if(col<0 or col>=n) return 100000;
        if(row==0)
            return matrix[0][col];
        
        if(dp[row][col]!=-1) return dp[row][col];
        int s=matrix[row][col]+f(row-1,col,matrix,dp,n);
        int ld=matrix[row][col]+f(row-1,col-1,matrix,dp,n);
        int rd=matrix[row][col]+f(row-1,col+1,matrix,dp,n);
        return dp[row][col]=min(s,min(ld,rd));
        
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int mini=INT_MAX;
        for(int i=0;i<n;++i)
        {
            mini=min(mini,f(m-1,i,matrix,dp,n));
        }
        return mini;
    }
};