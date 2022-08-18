class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int> pq;
        unordered_map<int,int> mp;
        int size=0;
        for(auto it:arr)
            mp[it]++;
        for(auto it: mp)pq.push(it.second);
        int ans=0,rem=0;
        while(rem<(arr.size()/2))
        {
            rem+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};