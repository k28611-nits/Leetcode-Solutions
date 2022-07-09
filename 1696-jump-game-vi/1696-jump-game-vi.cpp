class Solution{
    public:
int maxResult(vector<int>& nums, int k) {
	vector<int> dp(size(nums));
	dp[0] = nums[0];
	deque<int> q{ 0 };
	for(int i = 1; i < size(nums); i++) {
		if(q.front() < i - k) q.pop_front();  
		dp[i] = nums[i] + dp[q.front()];      
		while(!q.empty() && dp[q.back()] <= dp[i])  
		    q.pop_back();
		q.push_back(i);                            
	}
	return dp.back();
}
};