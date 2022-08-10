class Solution {
public:
    int totalways(vector<int>& nums,vector<int>& dp,int weight) {
        if ( weight == 0) return 1 ;
        if ( dp[weight] != -1) return dp[weight];
        dp[weight] = 0 ;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (weight >= nums[i]) dp[weight] += totalways(nums,dp,weight-nums[i]);
        }
        return dp[weight];
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        vector <int> dp (target+2,-1);
        int ans = totalways(nums,dp,target);
        return ans;
    }
};