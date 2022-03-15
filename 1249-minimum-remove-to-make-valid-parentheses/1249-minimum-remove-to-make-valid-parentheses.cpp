class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string a="";
        int n= s. length();
        int count=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
                count++;
            else if(s[i]==')')
            {
                if(count==0)
                    s[i]='@';
                else
                    count--;
            }
        }
        count=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')
                count++;
            else if(s[i]=='(')
            {
                if(count==0)
                    s[i]='@';
                else
                    count--;
            }
        }
        for(int i=0;i<n;++i)
            if(s[i]!='@')
                a.push_back(s[i]);
        return a;
    }
};