class Solution {
public:
    int fillCups(vector<int>& a) {
        int n = a.size();
        
        priority_queue<int> pq;
        
        for(auto &x: a){
            if(x != 0) pq.push(x);
        }
        int ans = 0;
        while(pq.size() >= 2){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            ans++;
            
            if(x-1 != 0) pq.push(x-1);
            if(y-1 != 0) pq.push(y-1); 
        }
        
        if(!pq.empty()) ans += pq.top();
        
        return ans;
    }
};