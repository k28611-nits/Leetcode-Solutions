class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for(int i=s.size()-1; i>= 0; i--) {
            if(s[i] == ' ' && ans > 0) break;
            else if(s[i] == ' ') continue;
            ans++;
        }
        return ans;
    }
};