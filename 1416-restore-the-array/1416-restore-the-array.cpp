class Solution {
public:
    int mod=1e9+7;
    int numberOfArrays(string s, int k) {
        // memset(dp,-1,sizeof(dp));
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            string str="";
            long long res=0;
            long x=0;
            if(s[i]=='0') continue;
            for(int j=i;j<min(n,i+9);j++){
                str.push_back(s[j]);
                x=x*10+s[j]-'0';
                if(x>k) break;
                res+=dp[j+1];
                res%=mod;
            }
            dp[i]=res;
        }
        return dp[0];
    }
};