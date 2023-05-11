class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()) {
            swap(nums1,nums2);
        }
        int s1=nums1.size(),s2=nums2.size();
        vector<int> dp(s1+1,0);
        vector<int> prev=dp;
        for(int i=1;i<=s1;i++) {
            prev=dp;
            for(int j=1;j<=s2;j++) {
                if(nums1[i-1]==nums2[j-1]) {
                    dp[j]=1+prev[j-1];
                } else {
                    dp[j]=max(prev[j],dp[j-1]);
                }
            }
        }
        return dp[s2];
    }
};