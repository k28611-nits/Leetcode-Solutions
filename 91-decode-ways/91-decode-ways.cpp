class Solution {
public:
    int f(int index, string& s,int n,vector<int>& dp)
    {
        if(index>=n) return 1;
        if(index<n and s[index]=='0') return 0;
        if(dp[index]!=-1) return dp[index];
        int ways=0;
        if(s[index]!='0') ways=f(index+1,s,n,dp);
         if(index+1 < n && ((s[index] == '1' && s[index+1] <= '9') || (s[index]=='2' && s[index+1] < '7')))
             ways+=f(index+2,s,n,dp);
        return dp[index]=ways;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return f(0,s,n,dp);
    }
};