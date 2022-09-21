class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        
        // first off calculate sum of all even elements
        
        int even_sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 0)
            {
                even_sum += nums[i];
            }
        }
        
        // res[i] will store the res of query[i]
        
        vector<int> res(queries.size());
        
        for(int i = 0; i < queries.size(); i++)
        {
            int idx = queries[i][1];
            
            int add = queries[i][0];
            
            // find the old val
            
            int old_val = nums[idx];
            
            // if old val is even then subtract from even sum
            
            if(old_val % 2 == 0)
            {
                even_sum -= old_val;
            }
            
            // find new val
            
            int new_val = old_val + add;
            
            // if new val is even then add to even_sum
            
            if(new_val % 2 == 0)
            {
                even_sum += new_val;
            }
            
            // update the nums[idx] with new val
            
            nums[idx] = new_val;
            
            // store the res
            
            res[i] = even_sum;
        }
        
        return res;
    }
};