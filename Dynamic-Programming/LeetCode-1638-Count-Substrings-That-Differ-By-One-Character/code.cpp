class Solution {
public:
    int countSubstrings(string s, string t) {
        vector < vector < int > > dp1(s.size()+2 , vector <int> (t.size()+2));
        vector < vector < int > > dp2(s.size()+2 , vector <int> (t.size()+2));
        int ans = 0 ;
        for ( int i = 1 ; i <= s.size() ; i++) {
            for ( int j = 1 ; j <= t.size() ; j++) {
                if ( s[i-1] == t[j-1] ) {
                     dp1[i][j] = 1 + dp1[i-1][j-1];
                     dp2[i][j] = dp2[i-1][j-1];
                }
                else dp2[i][j] = 1+dp1[i-1][j-1];
                ans += dp2[i][j];
            }
        }
        return ans;
    }
};