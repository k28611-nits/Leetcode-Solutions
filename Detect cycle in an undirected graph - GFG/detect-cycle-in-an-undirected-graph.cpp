// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
	void dfs(int root, vector <int> adj[], vector <bool> &vis, int parent, bool &f){
        vis[root] = true;
        for(auto i:adj[root]){
            if(!vis[i])
                dfs(i, adj, vis, root, f);
            else if(vis[i] && i != parent){
                f = true;
                return;
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector <bool> vis(V);
        bool f = false;
        for(int i=0; i<V; i++){
            if(!vis[i])
                dfs(i, adj, vis, -1, f);
            if(f)
                break;
        }
        return f;
    }
};
// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends