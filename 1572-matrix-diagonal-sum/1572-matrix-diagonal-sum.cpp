class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int x = 0, y = 0, n = mat.size();
        for(int i = 0 ; i < n ; ++i )
        {
            x += mat[i][i];//Primary
            y += mat[i][n - i - 1];//Secondary
        }
        if(n%2==0)
            return x+y;
        return x+y-mat[n/2][n/2];//Removes the central element as we have added it twice
    }
};