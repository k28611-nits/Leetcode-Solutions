/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* rec(int l, int r) {
        if (l > r) return NULL;
        
        int i = 0;
        while (m_inorder[i] != m_postorder[m_curr]) {
            i++;
        }
        
        m_curr--;
        TreeNode* node = new TreeNode(m_inorder[i]);
        node->right = rec(i+1, r);
        node->left = rec(l, i-1);
        return node;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        m_postorder = postorder, m_inorder = inorder, m_curr = inorder.size()-1;
        return rec(0, postorder.size()-1);
    }
    
private:
    int m_curr;
    vector<int> m_postorder, m_inorder;
};