class Solution {
public:
    int getMaximumGenerated(int n) {
        vector <int> nums ;
        nums.resize(n+5);
        nums[0] = 0 ;
        nums[1] = 1 ;
        int ans ;
        if ( n > 0) ans = 1 ;
        else ans = 0 ;
        for ( int i = 2 ; i <= n ; i++ ) {
            if (i%2 == 0) nums[i] = nums[i/2];
            else nums[i] = nums[i/2] + nums[i/2 + 1];
            ans = max(ans,nums[i]);
        }
        return ans;
    }
};