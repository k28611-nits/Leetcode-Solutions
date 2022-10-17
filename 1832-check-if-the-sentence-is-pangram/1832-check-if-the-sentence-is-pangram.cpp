class Solution {
public:
    bool checkIfPangram(string sentence) {
        int check[26]={0};
        for(char c: sentence)
        {
            check[c-'a']+=1;
        }
        for(int i=0;i<26;++i)
        {
            if(check[i]==0) return false;
        }
        return true;
    }
};