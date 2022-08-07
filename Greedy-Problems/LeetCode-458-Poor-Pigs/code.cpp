class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int dimensions = ceil((minutesToTest+0.0)/(minutesToDie+0.0));
        dimensions++ ;
        long long ans = 0;
        while(pow(dimensions,ans) < buckets) {
            ans++ ;
        }
        return ans;
    }
};