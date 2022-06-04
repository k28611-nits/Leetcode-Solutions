// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        vector<int> adj[N+1];
        vector<int> indegree(N+1, 0);
        for(int i = 0; i < M; i++) {
            int v = mat[i][1];
            int u = mat[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i = 1; i <= N; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while(q.empty() == false) {
            count++;
            while(q.empty() == false) {
                int curr = q.front();
                q.pop();
                for(auto it: adj[curr]) {
                    indegree[it]--;
                }
                indegree[curr] = -1;
            }
            for(int i = 1; i <= N; i++) {
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }        
        }
    
        return count; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends