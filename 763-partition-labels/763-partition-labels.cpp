class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> map;
        vector<int> ans;
        if(S.size()==0)return ans;
        for(int i=0;i<S.size();i++)
            map[S[i]]=i;
        int maxindex=0,lastindex=0;
        for(int i=0;i<S.size();i++)
        {
            maxindex=max(maxindex,map[S[i]]);
            if(i==maxindex)
            {
                ans.push_back(maxindex-lastindex+1);
                lastindex=i+1;
            }
        }
        return ans;
    }
};