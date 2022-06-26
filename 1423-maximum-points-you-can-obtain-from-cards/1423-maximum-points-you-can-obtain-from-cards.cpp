class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
       int l=k-1;
        int r=cp.size()-1;
        int leftsum = accumulate(cp.begin(),cp.begin()+k,0);
        int ans=leftsum;
        while(l>=0)
        {
            leftsum+=cp[r]-cp[l];
            ans=max(ans,leftsum);
            l--;
            r--;
        }
        return ans;
    }
};