class Solution {
public:
    int mod = 1e9 + 7;
    int possibleStrings(int n,int currChar,vector<vector<int>>& dp) {
        if (n == 1) return 1 ;
        if ( dp[n][currChar] != -1 ) return dp[n][currChar];
        if ( currChar == 0) return dp[n][currChar] = possibleStrings(n-1,1,dp)%mod;
        else if ( currChar == 1) return dp[n][currChar] = (possibleStrings(n-1,0,dp)%mod + possibleStrings(n-1,2,dp)%mod)%mod;
        else if ( currChar == 2) return dp[n][currChar] = (((possibleStrings(n-1,0,dp)%mod + possibleStrings(n-1,1,dp)%mod)%mod+possibleStrings(n-1,3,dp)%mod)%mod+possibleStrings(n-1,4,dp)%mod)%mod;
        else if ( currChar == 3) return dp[n][currChar] = (possibleStrings(n-1,2,dp)%mod+possibleStrings(n-1,4,dp)%mod)%mod;
        else return dp[n][currChar] = (possibleStrings(n-1,0,dp))%mod;
        
    }
    

    int countVowelPermutation(int n) {
        vector < vector <int> > dp (n+3, vector<int> (7,-1));
        long long ans = 0 ;
        for ( int i = 0 ; i < 5 ; i++) ans += (possibleStrings(n,i,dp)%mod)%mod;
        return ans%mod;
    }
};