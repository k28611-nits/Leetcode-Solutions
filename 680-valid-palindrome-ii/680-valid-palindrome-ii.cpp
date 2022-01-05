class Solution {
public:
    bool pali(string s, int index)
    {
        string temp1,temp2;
        for(int i=0;i<s.length();i++)
        {
            if(i!=index) temp1+=s[i];
        }
        temp2=temp1;
        reverse(temp2.begin(),temp2.end());
        if(temp1==temp2) return true;
        return false;
    }
    bool validPalindrome(string s) {
        string ans=s;
         for(int i=0,j=s.length()-1;i<s.length();++i,j--)
        {
            if(s[i]!=ans[j])
            {
                if(pali(s,i)) return true;
                if(pali(s,j)) return true;
                return false;
            }
        }
        return true;
    }
};