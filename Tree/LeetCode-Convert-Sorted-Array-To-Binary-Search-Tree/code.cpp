class Solution {
public:
    
    TreeNode* solution(vector<int>& nums, int l, int r) {
        if ( l == r) return NULL ;
        int mid = (l+r)/2 ;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solution(nums,l,mid);
        root->right = solution(nums,mid+1,r);
        return root ;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0 ;
        int r = nums.size();
        return solution(nums,l,r);
    }
};