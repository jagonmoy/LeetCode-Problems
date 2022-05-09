class Solution {
public:
    
      void dfs(vector<vector<int>>& grid,vector<vector<int>>& visit,int row,int col,int rowMax,int colMax,int& minRowIsland,int& maxRowIsland,int& minColIsland,int& maxColIsland) {
       if ( row == rowMax || row < 0 || col == colMax || col < 0 || visit[row][col] == 1 || grid[row][col] == 1) return;
       else visit[row][col] = 1 ;
          
       int dirX[] = {1,-1,0,0};
       int dirY[] = {0,0,-1,1};
       minRowIsland = min(minRowIsland,row);
       maxRowIsland = max(maxRowIsland,row);
       minColIsland = min(minColIsland,col);
       maxColIsland = max(maxColIsland,col);
       for ( int i = 0 ; i < 4 ; i++) dfs(grid,visit,row+dirX[i],col+dirY[i],rowMax,colMax,minRowIsland,maxRowIsland,minColIsland,maxColIsland);
       return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visit ;
        visit.resize(grid.size() , vector<int> (grid[0].size(),0));
        int minRowIsland,maxRowIsland,minColIsland,maxColIsland;
        int closedIsland = 0 ;
        for ( int i = 0 ; i < grid.size() ; i++) {
            for ( int j = 0 ; j < grid[0].size() ; j++) {
                if( visit[i][j] == 0 && grid[i][j] == 0) {
                    minRowIsland = grid.size()-1;
                    maxRowIsland = 0;
                    minColIsland = grid[0].size()-1;
                    maxColIsland = 0 ;
                    dfs(grid,visit,i,j,grid.size(),grid[0].size(),minRowIsland,maxRowIsland,minColIsland,maxColIsland);
                    if(minRowIsland > 0 && maxRowIsland < grid.size()-1 && minColIsland > 0 && maxColIsland < grid[0].size()-1) closedIsland++ ;
                }
            }
        }
        return closedIsland;
    }
};