class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> result;
        result.resize(numRows+1 , vector < int> (numRows+1,0));
        for ( int i = 1 ; i <= numRows ; i++) {
            for ( int j = 1 ; j <= i ; j++) {
                if ( j > 1 && j < i) {
                    result[i][j] = result[i-1][j-1]+result[i-1][j];
                }
                else result[i][j] = 1;
            }
        }

        vector < vector < int > > finalResult;
        finalResult.resize(numRows);
        for ( int i = 1 ; i <= numRows ; i++) {
            for( int j = 1 ; j <= numRows ; j++) {
                if ( result[i][j] != 0 )finalResult[i-1].push_back(result[i][j]);
            }
        }
    
        return finalResult ;
    }
};