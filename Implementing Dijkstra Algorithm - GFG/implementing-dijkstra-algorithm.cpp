// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
    
         vector<int> dis(V , INT_MAX);
         using  pii = pair<int , int>;
         priority_queue<pii , vector<pii> , greater<pii>> pq;
         dis[src] = 0;
         pq.push({0 , src});
         
         while (!pq.empty()){
         
             int v = pq.top().second;
             int d_v = pq.top().first;
             pq.pop();
             
             if (d_v > dis[v]) continue;
             
             for (auto edges : adj[v]){
             
                int to = edges[0];
                int len = edges[1];
    
                if (dis[v] + len < dis[to]) {
                    dis[to] = dis[v] + len;
                    pq.push({dis[to], to});
                }
                
             }
         }
         return dis;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends