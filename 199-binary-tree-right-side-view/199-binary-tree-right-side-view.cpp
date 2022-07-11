class Solution {
public:
    void dfs(TreeNode* root, int height) {
        if (!root) return;
        if (height == res.size())
            res.push_back(root->val);
        dfs(root->right, height + 1);
        dfs(root->left, height + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

private:
    vector<int> res;
};