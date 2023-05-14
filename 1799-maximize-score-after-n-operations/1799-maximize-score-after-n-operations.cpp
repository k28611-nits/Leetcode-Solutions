class Solution {
public:
    
    int n;
    map<pair<int,int>,int>dp;
    int solve(int o,int m,vector<int>&v){
        if(!m) return 0;
        if(dp.find({o,m})!=dp.end()) return dp[{o,m}];
        int ans=0;
        for(int i=0; i<=n; i++){
            if(m&(1<<i)){
            for(int j=0; j<=n; j++){
            if(i!=j && m&(1<<j)){
                 int temp=o*gcd(v[i],v[j])+solve(o+1,m^(1<<i)^(1<<j),v);
                 ans=max(temp,ans);
              }
            }
          }
        }
        return dp[{o,m}]=ans;
    }
    int maxScore(vector<int>& nums) {
        n=nums.size();
        dp.clear();
        return solve(1,(1<<n)-1,nums);
    }
};