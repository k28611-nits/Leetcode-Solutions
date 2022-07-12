class Solution {
public:

vector<vector<vector<int>>> dp;

// Changing states are i , a  and  b   => so 3D dp table required

int fun(int i,int a,int b,vector<vector<int>>& mat){
    if(i >= mat.size() || a < 0 || a >= mat[0].size() || b < 0 || b >= mat[0].size())
        return 0;
    if(dp[i][a][b] != -1)return dp[i][a][b];
    
    int ans = 0;
    
    for(int da = -1; da <= 1; da++){
        for(int db = -1; db <= 1; db++){

            int cur = fun(i+1, a+da, b+db, mat);
            ans = max(ans, cur);
            
        }
    }
    
    return dp[i][a][b] = ans + (a == b ? mat[i][a] : mat[i][a]+mat[i][b]);
}



int cherryPickup(vector<vector<int>>& grid) {
    
    int n = grid.size() , m = grid[0].size();
    dp = vector<vector<vector<int>>> (n,vector<vector<int>>(m,vector<int>(m,-1)));
    
    return fun(0,0,grid[0].size()-1,grid);
}
};