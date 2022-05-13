class Solution {
public:
    int countVowelStrings(int n) {
        vector < vector < int > > dp ;
        dp.resize(6,vector <int> (n+1,0));
        for ( int i = 1 ; i <= n ; i++) dp[1][i] = 1;
        for ( int i = 1 ; i <= 5 ; i++) dp[i][1] = i ;
        
        for ( int i = 2 ; i <= 5 ; i++) 
            for ( int j = 2 ; j <= n ; j++) 
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            
        return dp[5][n];
    }
};