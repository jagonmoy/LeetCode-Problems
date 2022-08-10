class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int squareNumbers = 0 ;
        
        for ( int i = 0 ; i < matrix.size() ; i++ ) squareNumbers += matrix[i][matrix[0].size()-1];
        for ( int i = 0 ; i < matrix[0].size() ; i++) squareNumbers += matrix[matrix.size()-1][i];
        squareNumbers -= matrix[matrix.size()-1][matrix[0].size()-1];
        
        for ( int i = matrix.size()-2 ; i >= 0 ; i--) {
            for ( int j = matrix[0].size()-2 ; j >= 0 ; j--) {
                if (matrix[i][j]) matrix[i][j] += min(matrix[i+1][j+1],min(matrix[i+1][j],matrix[i][j+1]));
                squareNumbers += matrix[i][j];
            }
        }
        
        return squareNumbers;
    }
};