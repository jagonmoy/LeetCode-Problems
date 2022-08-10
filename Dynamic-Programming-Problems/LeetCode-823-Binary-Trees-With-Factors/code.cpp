class Solution {
public:
    map<int,int> factor;
    int MOD = 1e9 + 7 ;
    void setUp(vector<int>& arr) {
        for ( int i = 0 ; i < arr.size() ; i++) factor[arr[i]] = i+1 ;
    }

    int solution(vector<int>& arr, vector<int>& dp, int index) {
        if ( index < 0) return 0 ;
        if ( dp[index] != -1) return dp[index];
        dp[index] = 1 ;
        for ( int i = 2 ; i*i <= arr[index] ; i++ ) {
            if ( arr[index] % i == 0 && factor[i] && factor[arr[index]/i]) {
                long long way1 = solution(arr,dp,factor[i]-1)%MOD;
                long long way2 = solution(arr,dp,factor[arr[index]/i]-1)%MOD;
                long long prod = (way1*way2)%MOD ;
                if ( i == arr[index]/i) dp[index] += prod;
                else dp[index] += ((2*prod)%MOD) ;
                dp[index] = dp[index]%MOD;
            }
        }
        return dp[index]%MOD;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        setUp(arr);
        vector <int> dp (arr.size()+2,-1);
        long long ans = 0 ;
        for ( int i = arr.size()-1 ; i >= 0 ; i-- ) ans += ((solution(arr,dp,i)%MOD)%MOD) ;   
        return ans%MOD ;
    }
};