class Solution {
public:
    vector<int> ans;
    void fill(TreeNode* root){
        if(!root)
            return;
        fill(root->left);
        fill(root->right);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        fill(root);
        return ans;
    }
};