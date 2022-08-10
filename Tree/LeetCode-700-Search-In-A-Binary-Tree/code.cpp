class Solution {
public:
        
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL ;
        if (root -> val == val) return root;
        TreeNode* tree1 = searchBST(root->left,val);
        if (!tree1) {
            TreeNode* tree2 = searchBST(root->right,val);
            return tree2 ;
        }
        else return tree1 ;
    }
};