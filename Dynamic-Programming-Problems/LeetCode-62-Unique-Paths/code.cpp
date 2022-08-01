class Solution {
public:
    int totalPaths(int x, int y, vector < vector < int > > &dp) {
        if ( x == 1 && y == 1) return 1 ;
        if ( x < 0 || y < 0 ) return 0 ;
        if (dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = totalPaths(x-1,y,dp) + totalPaths(x,y-1,dp);
    }
    
    
    int uniquePaths(int m, int n) {
        vector < vector <int> > dp (m+1, vector<int> (n+1,-1));
        return totalPaths(m,n,dp);
    }
};