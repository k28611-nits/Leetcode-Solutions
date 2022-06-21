class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) {
        int n=a.size();
        int i=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(i=0;i<n-1;i++)
        {
            if(a[i]<a[i+1])
                pq.push(a[i+1]-a[i]);
            if(pq.size()>l)
            {
                int temp = pq.top();
                pq.pop();
                b-=temp;
                if(b<0)
                    break;
            }
        }
        return i;
    }
};