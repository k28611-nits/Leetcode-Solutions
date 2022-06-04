// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
    int findpar(vector<int>&parent,int x){
    if(x== parent[x]){
        return x;
    }
    
    return parent[x] = findpar(parent,parent[x]);
}

void Union(vector<int>&parent,vector<int>&rank,int x,int y){
    
    x = findpar(parent,x);
    y = findpar(parent,y);
    
    if(rank[x] > rank[y]){
        parent[y]= x;
    }
    else if(rank[x] < rank[y]){
        parent[x] =y;
    }
    else{
        parent[y]=x;
    }
}

   int spanningTree(int V, vector<vector<int>> adj[])
   {
       // code here
       vector<int> parent(V);
       vector<int>rank(V,0);
       multimap<int,pair<int,int>> mp;
       vector<pair<int,int>> mst;
       for(int i=0;i<V;i++){
           parent[i] =i;
       }
       for(int i= 0;i<V;i++){
           
           for(auto it : adj[i]){
               mp.insert(make_pair(it[1],make_pair(i,it[0])));
           }
       }
       
       int cost =0;
       multimap<int, pair<int,int>>::iterator it;
       for( it = mp.begin();it!=mp.end();it++){
           if(findpar(parent,it->second.first) != findpar(parent,it->second.second)){
               cost += it->first;
               mst.push_back(make_pair(it->second.first,it->second.second));
               Union(parent,rank,it->second.first,it->second.second);            }
       }
       
       
       return cost;
      
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends