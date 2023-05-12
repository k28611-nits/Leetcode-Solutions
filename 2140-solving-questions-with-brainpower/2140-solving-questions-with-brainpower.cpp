class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long dp[n+1];
        long long ans = 0;
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            if(questions[i][1]+i+1 >= n){
                dp[i] = max((long long)questions[i][0],dp[i+1]);
            }else{
                dp[i] = max(dp[i+questions[i][1]+1]+questions[i][0],dp[i+1]);
            }
            ans = max(ans,dp[i]);
        }   
        return ans;
    }
};