class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int> >ans;
        int i=0,j=0;
        while(i<a.size() and j<b.size()){
            int l=max(a[i][0],b[j][0]);
            int r=min(a[i][1],b[j][1]);
            if(l<=r)ans.push_back({l,r});
            if(a[i][1]<b[j][1])i++;
            else j++;
        }
        return ans;
    }
};