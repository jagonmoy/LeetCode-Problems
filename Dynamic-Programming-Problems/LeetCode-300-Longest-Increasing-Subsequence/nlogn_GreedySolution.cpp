class Solution {
public:
    int minNumberGreaterEqualX(int x, vector<int>& ans) {
        int l = -1 ;
        int r = ans.size();
        while(r > l+1) {
            int m = (l+r)/2 ;
            if ( x >= ans[m] ) l = m ;
            else r = m ;
        }
        return ( l == -1 ? 0 : l);
    }
     
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        for ( int i = 0 ; i < nums.size() ; i++) {
            if ( !ans.size() || nums[i] > ans[ans.size()-1]) {
                ans.push_back(nums[i]);
            }
            else {
                auto it = lower_bound(ans.begin(),ans.end(),nums[i]);
                *it = nums[i];
            }
            
        }
        return ans.size() ;
    }
};