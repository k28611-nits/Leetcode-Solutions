class Solution {
public:
    
    bool solve(TreeNode*p,TreeNode* q){
        if(p==NULL and q==NULL)return true;
        if(p==NULL || q==NULL)return false;
        if(p->val!=q->val)return false;
        return solve(p->left,q->left) and solve(p->right,q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL and q==NULL)return true;
        if(p==NULL || q==NULL)return false;
        return solve(p,q);
        
    }
};