/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or p==root or q==root) return root;
        TreeNode* left_lca=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_lca=lowestCommonAncestor(root->right,p,q);
        if(left_lca==NULL) return right_lca;
        else if(right_lca==NULL) return left_lca;
        else return root;
    }
};