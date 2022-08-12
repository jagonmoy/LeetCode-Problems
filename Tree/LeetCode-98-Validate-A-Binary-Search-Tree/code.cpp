class Solution {
public:
    
    bool solution(TreeNode* root,long long minVal,long long maxVal) {
        if (!root) return true ;
        if (root->val <= minVal || root -> val >= maxVal) return false ;
        return solution(root->left,minVal,root->val) && solution(root->right,root->val,maxVal) ;
    }
    
    bool isValidBST(TreeNode* root) {
        return solution(root,LONG_MIN,LONG_MAX);
    }
};