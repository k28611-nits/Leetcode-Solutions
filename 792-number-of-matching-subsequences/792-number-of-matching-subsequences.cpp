class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
     int count=0,n=s.size();
     unordered_map<string,int> mp;
        for(int i=0;i<words.size();++i)
            mp[words[i]]++;
        for(auto x:mp)
        {
            int s1=0,s2=0;
            string p=x.first;
            int k=p.size();
            while(s1<n and s2<k)
            {
                if(p[s2]==s[s1])
                    s1++,s2++;
                else s1++;
            }if(s2==k) count+=x.second;
        }return count;
    }
};