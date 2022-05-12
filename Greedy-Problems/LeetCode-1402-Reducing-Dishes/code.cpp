class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int res = 0 ;
        for(int i = 0 ; i < satisfaction.size() ; i++) {
            int sum = 0 ;
            for (int j = i ; j < satisfaction.size() ; j++) sum += ((j-i+1)*satisfaction[j]);
            res = max(sum,res);
        }
        return res ;
    }
};