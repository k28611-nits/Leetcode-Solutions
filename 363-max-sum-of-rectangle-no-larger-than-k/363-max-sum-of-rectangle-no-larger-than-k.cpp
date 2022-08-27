class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < m; i++)
        {
            for(int j = i; j < m; j++)
            {
                int rowsum = 0;
                set<int> tmp = {0};
                for(int f = 0; f < n; f++)
                {
                    rowsum += matrix[f][j];
                    if(i > 0)
                        rowsum -= matrix[f][i-1];
                    auto lb = tmp.lower_bound(rowsum-k);
                    if(lb != tmp.end())
                        ans = max(ans, rowsum-*lb);
                    tmp.insert(rowsum);
                }
            }
        }
        return ans;
    }
};