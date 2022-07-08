class Solution {
public:
    int f(int row,int col,vector<vector<int>>& dp, vector<vector<int>>& t,int m)
    {
        if(row==m-1) return t[m-1][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int d=t[row][col] + f(row+1,col,dp,t,m);
        int dg=t[row][col] + f(row+1,col+1,dp,t,m);
        return dp[row][col]=min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& t) {
        int m=t.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return f(0,0,dp,t,m);
    }
};