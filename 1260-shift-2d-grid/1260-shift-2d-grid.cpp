class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int h = grid.size();
        int w = grid[0].size();
        int total = h*w;
        
        vector<vector<int>> r(h,vector<int>(w,0));
        for(int i=0;i<total;i++)
        {
            int j=(i+k)%total;
            
            r[j/w][j%w] = grid[i/w][i%w];
        }
        return r;
    }
};