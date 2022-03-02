class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> c1(26, 0), c2(26, 0);
        for (char c: s) c1[c-'a'] ++;
        for (char c: t) c2[c-'a'] ++;

        for (int i = 0; i < 26; ++i) {
            if (c1[i] != c2[i]) 
                return false;
        }
        return true;
    }
};