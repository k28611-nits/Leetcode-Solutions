class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        vector<int> ans;
        
        if(p.size() > s.size())
            return ans;
        
        int left = 0, right = 0;
        while(right < p.size()){
            phash[p[right] - 'a']++;
            shash[s[right] - 'a']++;
            right++;
        }
        right--;
        while(right < s.size()){
            if(phash == shash)
                ans.push_back(left);
            right++;
            if(right != s.size()){
                shash[s[right] - 'a'] ++;
                shash[s[left] - 'a'] --;
            }
            left++;
        }
        return ans;
    }
};