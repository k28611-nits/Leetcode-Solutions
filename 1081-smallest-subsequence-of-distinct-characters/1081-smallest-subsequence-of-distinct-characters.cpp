class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
        }
        vector<int> visited(26,0);
        
        string ans="";
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']--;
            if(!visited[s[i]-'a']){
                while(ans.length()>0 && ans.back()>s[i] && count[ans.back()-'a']>0){
                    visited[ans.back()-'a']=0;
                    ans.pop_back();
                }
                ans+=s[i];
                visited[s[i]-'a']=1;
            }
        }
        return ans; 
    }
};