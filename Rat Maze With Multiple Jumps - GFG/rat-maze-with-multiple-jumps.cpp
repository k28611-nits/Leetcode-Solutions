// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool solve(vector<vector<int>>&ans,vector<vector<int>>&mat,int i,int j,int n,int m)
   {
       if(i<0 || j<0 || i>=n || j>=m )
       return false;
       
       
       if(i==n-1 and j==m-1)
       {   
           ans[i][j]=1;
           return true;
       }
       
       if(mat[i][j]==0)
       return false;
       
       
       ans[i][j]=1;
       
       for(int k=1;k<=mat[i][j];k++)
       {
           if( j+k<m)
               if(solve(ans,mat,i,j+k,n,m))
                  return true;
                  
           if(i+k<n)
               if(solve(ans,mat,i+k,j,n,m))
                  return true;
       }
       
       ans[i][j]=0;
       return false;
       
   }
vector<vector<int>> ShortestDistance(vector<vector<int>>&mat)
{
   int n=mat.size(),m=mat[0].size();
   vector<vector<int>>ans(n,vector<int>(m,0));
   
   if(solve(ans,mat,0,0,n,m))
   return ans;
   
   return{{-1}};
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends