class Solution {
public:
    #define ll long long
    static bool comp(pair<int, int>a, pair<int, int>b){
        if(a.second >= b.second)
            return false;
        return true;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>>arr;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            arr.push_back({nums1[i], nums2[i]});
        }

        sort(arr.begin(), arr.end(), comp);

        vector<ll>maxSum(n, 0);
        priority_queue<int, vector<int>, greater<int>>pq;
        ll sum = 0;

        for(int i=n-1;i>=0;i--){
            if(pq.size() < k){
                pq.push(arr[i].first);
                sum+=(ll)arr[i].first;
                if(pq.size() == k){
                    maxSum[i] = sum;
                }
            }
            else if (pq.size() == k){
                int temp = pq.top();
                if(temp < arr[i].first){
                    pq.pop();
                    sum-=temp;
                    pq.push(arr[i].first);
                    sum+=(ll)arr[i].first;
                }

                maxSum[i] = sum;
            }
        }

        ll res = 0;
        for(int i=0;i<n;i++){
            res = max(res, (ll)arr[i].second * (ll)maxSum[i]);
        }

        return res;
    }
};