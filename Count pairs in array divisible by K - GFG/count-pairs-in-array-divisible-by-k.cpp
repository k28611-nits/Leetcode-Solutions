// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int k)
    {
         map<long long ,long long> m;
      for(int i=0;i<n;i++){
          m[A[i]%k]++;      // this is for couting how many elements with remainder A[i]%k;
      }
      long long int ans=0;
      for(int i=0;i<k;i++){
          if(i!=k-i){      // if k=10 then 45 and 55 gives same remainder then we have to deal with that seperately
              ans+=m[i]*(m[k-i]);
          }
          else
          ans+=m[i]*(m[i]-1);
      }
      ans/=2;
      ans+= (m[0]*(m[0]-1))/2;  // if remainder is zero.
      return ans;
   }
    
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends