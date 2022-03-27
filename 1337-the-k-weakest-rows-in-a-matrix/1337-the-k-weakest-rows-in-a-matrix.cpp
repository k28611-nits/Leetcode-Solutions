class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue < pair<int,int> > max_heap;
        for(int i=0;i<mat.size();i++){
            int count = 0;
        for(int j=0 ; j < mat[i].size() ; j++)
            if(mat[i][j] == 1) count++;
        max_heap.push({count,i});
        if(max_heap.size() > k)
            max_heap.pop();
        }
        vector<int> ans;
        for(int i = 0 ; i < k;i++){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};