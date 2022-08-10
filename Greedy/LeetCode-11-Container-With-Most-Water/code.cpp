class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0 ;
        int r = height.size()-1;
        long long res = 0 ;
        while(l < r) {
            long long temp = (r-l)*min(height[l],height[r]);
            res = max(res,temp);
            if ( height[l] < height[r]) l++ ;
            else r-- ;
        } 
        return res ;
    }
};