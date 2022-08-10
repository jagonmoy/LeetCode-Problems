class Solution {
public:
    
    int lis(vector<int>& nums,vector<vector<int>>& dp,int n,int lastPickedIndex) {
        if ( n < 0) return 1 ;
        if ( dp[n][lastPickedIndex] != -1) return dp[n][lastPickedIndex];
        int way1 = 0 , way2 = 0 ;
        if ( nums[n] < nums[lastPickedIndex]) way1 = 1+lis(nums,dp,n-1,n);
        way2 = lis(nums,dp,n-1,lastPickedIndex);
        return dp[n][lastPickedIndex] = max(way1,way2);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        nums.push_back(99999);
        vector<vector<int>> dp (nums.size()+2,vector<int> (nums.size()+2,-1));
        return lis(nums,dp,nums.size()-2,nums.size()-1)-1;
    }
};