class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximum = 1 ;
        bool fact = true ;
        for ( int i = 0 ; i < nums.size() -1 ; i++ ) {
            if ( max(nums[i],maximum-1) == 0 && i < nums.size()-1) {
                fact = false ;
                break ;
            }
            else maximum = max(nums[i],maximum-1);
        }
        return fact;
    }
};