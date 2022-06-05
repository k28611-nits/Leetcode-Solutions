// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPossible(long hr[],long acc[],long limit,long mx,long m,long n){
    long long int sum = 0;
    for(long i=0;i<n;i++){
        if(limit*acc[i] + hr[i] >= mx){
            sum += (limit*acc[i] + hr[i]);
        }
    }
    return (sum >= m);
}
    long buzzTime(long n, long m, long mx, long hr[], long acc[])
    {
        long long int r = 1000000007;
        long long int l = 0;
        while(l<=r){
            long long int mid = l + (r-l)/2;
            if(isPossible(hr,acc,mid,mx,m,n)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends