class Solution {
    const int MOD = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);

        ++ dp[zero];
        ++ dp[one];
        for(int i = min(zero, one) + 1; i < dp.size(); ++i){
            if(i >= zero){
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            if(i >= one){
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
        }

        int answer = 0;
        for(int i = low; i <= high; ++i){
            answer = (answer + dp[i]) % MOD ;
        }

        return answer;
    }
};