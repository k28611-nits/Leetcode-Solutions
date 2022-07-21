class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>v(k,0);
        
        priority_queue<pair<int,int>>pq;  
        for(int i=0;i<nums.size();i++){   
            pq.push({nums[i],i});
        }
        for(int i=0;i<k;i++){
           v[i]=pq.top().second; 
            pq.pop();
        }
        sort(v.begin(),v.end());  
         for(int i=0;i<k;i++){
           v[i]=nums[v[i]];      
        }
        return v;
    }
};