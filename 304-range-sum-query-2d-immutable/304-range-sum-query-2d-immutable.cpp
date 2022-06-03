class NumMatrix {
    vector<vector<int> > sums;
public:
    NumMatrix(vector<vector<int>>& m) {
        sums.resize(1 + size(m), vector<int>(1 + size(m[0])));        
        for(int r = 1; r <= size(m); r++) 
            for(int c = 1; c <= size(m[0]); c++) 
                sums[r][c] += m[r - 1][c - 1] + sums[r - 1][c] + sums[r][c - 1] - sums[r - 1][c - 1];
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return sums[r2 + 1][c2 + 1] - sums[r1][c2 + 1] - sums[r2 + 1][c1] + sums[r1][c1];
    }
};