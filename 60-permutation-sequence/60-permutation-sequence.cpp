class Solution {
public:
   string getPermutation(int n, int k) {
        vector<int> nums;
        // taking factorial that is all the number of factorial;
        int fact = 1;
        // storing number in nums vec 
        // also we take factorial till n-1 only because we have to calculate only on the 
        // specific permutions after taking the first element out that is k / fact on line 21
        for(int i = 1; i < n; i++) {
            nums.push_back(i);
            fact *= i;
        }
        nums.push_back(n);
        // reducing k by 1 because of 0 based indexing
        k--;
        string ans = "";
        while(true) {
            // now add the the top number for current iteration
            ans += to_string(nums[k / fact]);
            // now remove that top number to get the permutation of remaining nums elements
            nums.erase(nums.begin() + k / fact);
            // if the vector size get 0 then it means all the elements used in permutationa 
            // and all the we go the desired permutation
            if(nums.size() == 0) 
                break;
            // if not then go for next iteration and for that set new k
            // new k will be the nubmer of permutation required with the left out element in the
            // nums array and k will be k % fact and so with the factorial it will the 
            // factorial of nums.size()-1 elements that is fact will be fact / nums.size();
            k %= fact;
            fact /= nums.size();
        }
        return ans;
    }
};