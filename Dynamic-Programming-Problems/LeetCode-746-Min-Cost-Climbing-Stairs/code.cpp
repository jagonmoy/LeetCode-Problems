class Solution {
public:
    
    int dpFunction(int index,int start,vector<vector<int>>& dp,vector<int>& cost) { 
        if (index >= cost.size()) return dp[index][start]=0 ;
        if (dp[index][start] != -1) return dp[index][start];
        return dp[index][start]= min(cost[index]+dpFunction(index+1,start,dp,cost),cost[index]+dpFunction(index+2,start,dp,cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<vector<int>> dp ;
        dp.resize(cost.size()+2,vector<int> (3,-1));
        int minCost = min(dpFunction(0,0,dp,cost),dpFunction(1,1,dp,cost));
        return minCost;
    }
};