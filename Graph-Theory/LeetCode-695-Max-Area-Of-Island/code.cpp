class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& visit, int row , int col , int rowMax, int colMax) {
       if ( row == rowMax || row < 0 || col == colMax || col < 0 || visit[row][col] == 1 || grid[row][col] == 0) return 0 ;
       else visit[row][col] = 1 ;
       int dirX[] = {1,-1,0,0};
       int dirY[] = {0,0,-1,1};
       int totalArea = 0 ;
       for ( int i = 0 ; i < 4 ; i++) totalArea += dfs(grid,visit,row+dirX[i],col+dirY[i],rowMax,colMax);
       return totalArea+1 ;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visit ;
        visit.resize(grid.size() , vector<int> (grid[0].size(),0));
        int maxArea = 0 ;
        for ( int i = 0 ; i < grid.size() ; i++) {
            for ( int j = 0 ; j < grid[0].size() ; j++) {
                maxArea = max(maxArea,dfs(grid,visit,i,j,grid.size(),grid[0].size()));
            }
        }
        return maxArea;
    }
};