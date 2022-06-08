class Solution {
public:
    int removePalindromeSub(string s) {
        int l = 0, r = s.size() - 1;
        
        while(l <= r){ 
            if(s[l] != s[r]) // s is not a palindrom
                return 2; // thus we need 2 steps to remove all characters
            l++, r--; // moving l to the right, r to the left
        }
        
        return 1; // a is a palindrom, thus we need 1 step to remove whole string
    }
};