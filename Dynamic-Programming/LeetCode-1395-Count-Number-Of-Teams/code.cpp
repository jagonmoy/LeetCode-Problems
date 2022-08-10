class Solution {
public:

    int numTeams(vector<int>& rating) {
        vector <int> greater (rating.size()+3,0);
        vector <int> lesser (rating.size()+3,0);
        
        int totalTeam = 0 ;
        
        for ( int i = 0 ; i < rating.size() ; i++) {
            for ( int j = i+1 ; j < rating.size() ; j++) {
                if ( rating[j] > rating[i]) {
                    greater[j]++ ;
                    if(greater[i]) totalTeam += greater[i] ;
                }
                if ( rating[j] < rating[i]) {
                    lesser[j]++ ;
                    if (lesser[i]) totalTeam += lesser[i] ;
                }
            }
        }
        return totalTeam ;
    }
};