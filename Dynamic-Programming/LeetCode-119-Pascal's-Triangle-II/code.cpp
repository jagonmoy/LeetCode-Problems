class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <vector<int>> result;
        result.resize(35 , vector < int> (35,0));
        for ( int i = 1 ; i <= 34 ; i++) {
            for ( int j = 1 ; j <= i ; j++) {
                if ( j > 1 && j < i) {
                    result[i][j] = result[i-1][j-1]+result[i-1][j];
                }
                else result[i][j] = 1;
            }
        }

        vector < vector < int > > finalResult;
        finalResult.resize(35);
        for ( int i = 1 ; i <= 34 ; i++) {
            for( int j = 1 ; j <= 34 ; j++) {
                if ( result[i][j] != 0 )finalResult[i-1].push_back(result[i][j]);
            }
        }
    
        vector <int> finalRow ;
        for ( int i = 0 ; i < finalResult[rowIndex].size() ; i++) finalRow.push_back(finalResult[rowIndex][i]);
        return finalRow;
    }
};