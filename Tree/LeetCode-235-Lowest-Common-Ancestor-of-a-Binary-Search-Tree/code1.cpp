class Solution {
public:
    TreeNode* ans ;
    bool found = false;
    map<TreeNode*,int> val ;
    
    void dfs(TreeNode* root,TreeNode* p, TreeNode* q ) {
        if (!root || found) return ;
        if ( root == p || root == q) val[root] = 1 ;
        dfs(root->left,p,q);
        dfs(root->right,p,q);
        if(!found && root->left) val[root] += val[root->left];
        if(!found && root->right) val[root] += val[root->right];
        if (val[root] == 2 && !found) {
            found = true ;
            ans = root ;
        }
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans ;
    }
};