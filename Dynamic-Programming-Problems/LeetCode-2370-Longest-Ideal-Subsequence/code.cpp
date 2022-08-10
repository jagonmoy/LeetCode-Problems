class Solution {
public:
    
    int longSubsequence(string& s, int& k, int index,int past,vector<vector<int>>& dp) {
        if ( index < 0) return 0 ;
        if ( dp[index][past] != -1) return dp[index][past];
        int way1 = 0 ,way2 = 0 ; 
        if ( past == 130 || abs(s[index]-past) <= k) way1 = 1 + longSubsequence(s,k,index-1,s[index],dp);
        way2 = longSubsequence(s,k,index-1,past,dp);
        return dp[index][past] = max(way1,way2);
    }
    
    int longestIdealString(string s, int k) {
         vector<vector<int>> dp(s.size()+2,vector<int> (135,-1));
         return longSubsequence(s,k,s.size()-1,130,dp);
    }
};