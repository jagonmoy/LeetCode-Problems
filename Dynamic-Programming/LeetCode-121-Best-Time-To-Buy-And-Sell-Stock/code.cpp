class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() > 1 ) {
            int profit = 0 ;
            int buyDay = prices[0];
            for ( int i = 1 ; i < prices.size() ; i++) {
                if ( i <= prices.size()-2 && buyDay > prices[i]) buyDay = min(buyDay,prices[i]);
                else profit = max(profit,prices[i]-buyDay);
                
            }
            return profit ;
        }   
        else return 0 ;
    }
};