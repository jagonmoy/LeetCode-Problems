class Solution {
public:
    
    int edgeScore(vector<int>& edges) {
        vector <long long> inputCount(edges.size()+2,0);
        for ( int i = 0 ; i < edges.size() ; i++) {
            inputCount[edges[i]] += i ;
        }
        long long maximum = -1 , node = -1 ;
        for ( int i = 0 ; i < edges.size() ; i++) {
            if ( inputCount[i] > maximum) {
                maximum = inputCount[i];
                node = i ;
            } 
            else if ( inputCount[i] == maximum && i < node) {
                node = i ;
            }
        }
        return node ;
    }
};