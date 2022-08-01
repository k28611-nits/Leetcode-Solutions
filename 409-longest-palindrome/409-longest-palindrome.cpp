class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto it:s)
            mp[it]++;
        int count=0;
        for(auto it: mp)
        {
            if(it.second %2!=0) count++;
        }
        if(count>1) return s.size()-count+1;
        return s.size();
    }
};