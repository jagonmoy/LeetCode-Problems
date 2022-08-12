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
    map <pair<TreeNode*,int>,int> dp ;
    int cnt = 0 ;
    int solution(TreeNode* root,int state) {
        if (!root) return 0;
        if (dp[{root,state}]) return dp[{root,state}];
        if (state) dp[{root,state}] = root->val;
        else dp[{root,state}] = 0 ;
        
        if (state) {
            int way1 = 0 , way2 = 0 ;
            way1 = solution(root->left,!state);
            way2 = solution(root->right,!state);
            return dp[{root,state}] += way1 + way2;
        }
        else {
            int way1 = 0 , way2 = 0, way3 = 0 , way4 = 0 ; ;
            way1 = solution(root->left,state) + solution(root->right,!state);
            way2 = solution(root->left,!state) + solution(root->right,state);
            way3 = solution(root->left,state) + solution(root->right,state);
            way4 = solution(root->left,!state) + solution(root->right,!state);
            return dp[{root,state}]  += max(way1,max(way2,max(way3,way4)));
        }
    }
    
    
    
    int rob(TreeNode* root) {
        return max(solution(root,0),solution(root,1)) ;
    }
};