class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int right=0,left=0,len=0,n=s.size();
        while(right<n)
        {
            if(mp[s[right]]!=-1) left=max(mp[s[right]]+1,left);
            mp[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};