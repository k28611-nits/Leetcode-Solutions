class Solution {
public:
    int longestConsecutive(vector<int>& a) {
         int ans=0;
        int n=a.size();
      unordered_set<int>s;
      
      for(int i=0;i<n;i++)
         s.insert(a[i]);
        
        for(int i=0;i<n;i++){ 
         if(s.find(a[i]-1)==s.end()){
             int j=a[i];
            while(s.find(j)!=s.end())
                j++;
                  
             ans=max(ans,j-a[i]);
              }
          }
      return ans;
    }
};