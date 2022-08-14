class Solution {
public:
    
    int matrix(vector<vector<int>>& grid, int x, int y) {
        int maximum = -1 ;
        for ( int i = x-1 ; i <= x+1 ; i++) {
            for ( int j = y-1 ; j <= y+1 ; j++) {
                // cout << i << " " << j << ". " ;
                maximum = max(maximum,grid[i][j]);
            }
            // cout << endl;
        }
        // cout << maximum << endl;
        return maximum;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector < vector<int>> result ;
        for ( int i = 0 ; i < grid.size() ; i++) {
            vector <int> samoyik;
            for ( int j = 0 ; j < grid[i].size() ; j++) {
                if ( i - 1 >= 0 && j - 1 >= 0 && i+1 < grid.size() && j+1 < grid[i].size() ) {
                    samoyik.push_back(matrix(grid,i,j));
                }
            }
            if(samoyik.size())result.push_back(samoyik);
            samoyik.clear();
        }
        return result;
    }
};