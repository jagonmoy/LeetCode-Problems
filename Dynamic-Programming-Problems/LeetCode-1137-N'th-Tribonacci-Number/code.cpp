class Solution {
public:
    int tribonacci(int n) {
        vector < int > trib ;
        trib.resize(n+5,0);
        trib[0] = 0 ;
        trib[1] = 1 ;
        trib[2] = 1 ;
        if ( n > 2) {
            for ( int i = 3 ; i <= n ; i++) trib[i] = trib[i-1]+trib[i-2]+trib[i-3];
        }
        return trib[n];
    }
};