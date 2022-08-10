class Solution {
public:
    TreeNode* rec(vector<int>& nums, int start, int end) {
        if (start >= end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = rec(nums, start, mid);
        node->right = rec(nums, mid+1, end);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return rec(nums, 0, nums.size());
    }
};