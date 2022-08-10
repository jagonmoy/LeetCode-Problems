class Solution {
public:
    
    int dpFunction(int index,vector<int>& dp) {
        if ( index == 0) return 1 ;
        if ( dp[index] != -1) return dp[index];
        int add1 = 0 ;
        int add2 = 0 ;
        if ( index-1 >= 0 ) add1 = dpFunction(index-1,dp);
        if ( index-2 >= 0 ) add2 = dpFunction(index-2,dp);
        return dp[index] = add1 + add2;
    }
    
    int climbStairs(int n) {
        vector<int>dp;
        dp.resize(n+2,-1);
        int steps = dpFunction(n,dp);
        return steps;
    }
};