class NumArray {
public:
    NumArray(vector<int>& nums) {
        vec = nums;
        for (int i = 1; i < nums.size(); i++)
            vec[i] = nums[i] + vec[i-1];
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return vec[j];
        return vec[j] - vec[i-1];
    }
private:
    vector<int> vec;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */