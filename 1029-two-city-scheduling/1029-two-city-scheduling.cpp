class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> a;
        int ans=0;
        for(int i=0;i<costs.size();++i)
        {
            ans+=costs[i][0];
            a.push_back(costs[i][1]-costs[i][0]);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<costs.size()/2;++i)
        {
            ans+=a[i];
        }
        return ans;    
    }
};