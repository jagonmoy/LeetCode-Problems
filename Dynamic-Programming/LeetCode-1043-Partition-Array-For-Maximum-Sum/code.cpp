class Solution {
public:
    int maxPartition(vector<int>& arr,int i, int k,vector<int>& dp) {
            if ( i <= 0 ) return 0 ;
            if ( dp[i] != -1) return dp[i];
            int currMax = 0 ;
            for ( int j = i ; j >= max(i-k+1,1) ; j--) {
                currMax = max(currMax,arr[j-1]);
                dp[i] = max(dp[i],(i-j+1)*currMax + maxPartition(arr,j-1,k,dp));
            }
            return dp[i];
    }
                            
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector <int> dp ;
        dp.resize(arr.size()+3,-1);
        int ans = maxPartition(arr,arr.size(),k,dp) ;
        return ans ;
    }
};