class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m1; 
    stack<int>st;
     int n=nums2.size();
    
  for(int i=n-1;i>=0;i--){
      
      while(!st.empty() && st.top()<nums2[i]){
          st.pop();
      }

      if(st.empty()){
          m1[nums2[i]]=-1;
      }
      
      else{
          m1[nums2[i]]=st.top();
      }
      
      st.push(nums2[i]);

      
  }
    vector<int>ans;
    
    for(auto i:nums1){
        ans.push_back(m1[i]);
    }
    
    
    return ans;
    }
};