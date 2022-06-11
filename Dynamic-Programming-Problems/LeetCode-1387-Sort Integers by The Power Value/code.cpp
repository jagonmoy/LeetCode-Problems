class Solution {
public:
    int stepCalculator(int n , map <int,int>& dp) {
        if (dp[n]) return dp[n] ;
        if (n % 2 == 0 ) return dp[n] = 1+stepCalculator(n/2,dp);
        else return dp[n] = stepCalculator(n*3+1,dp)+1;
        return 0 ;
    }
        
    
    int getKth(int lo, int hi, int k) {
        map <int,int> dp ;
        dp[1] = 1 ;
        for ( int i = lo ; i <= hi ; i++ ) stepCalculator(i,dp);
        vector < pair <int,int> > numbers ;
        for ( int i = lo ; i <= hi ; i++) numbers.push_back({dp[i],i});
        sort(numbers.begin(),numbers.end());
        return max(numbers[k-1].second,1);
    }
};