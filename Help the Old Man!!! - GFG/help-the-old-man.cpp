// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> shiftPile(int N, int n){
        vector<vector<int>> v;
        help(1,3,2,v , N);
        return v[n-1];
    }
    void help(int src, int dest , int helper ,vector<vector<int>> &v ,int n ){
        if(n ==  0) return;
        help(src , helper , dest , v , n-1 );
        v.push_back({src , dest});
        help( helper , dest , src , v , n-1 );
    }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends