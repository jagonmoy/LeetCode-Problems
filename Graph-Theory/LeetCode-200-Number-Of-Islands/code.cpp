class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visit,int row, int col, int maxRow , int maxCol) {
        if ( row == maxRow || row < 0 || col == maxCol || col < 0 || visit[row][col] == 1 || grid[row][col] == '0') return ;
        else visit[row][col] = 1 ;
        int dirX[] = {1,-1,0,0};
        int dirY[] = {0,0,1,-1};
        for ( int i = 0 ; i < 4 ; i++)dfs(grid,visit,row+dirX[i],col+dirY[i],maxRow,maxCol);
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visit;
        visit.resize(grid.size(),vector<int>(grid[0].size(),0));
        int island = 0 ;
        for ( int i = 0 ; i < grid.size() ; i++) {
            for ( int j = 0 ; j < grid[0].size() ; j++) {
                if ( visit[i][j] == 0 && grid[i][j] == '1') {
                    dfs(grid,visit,i,j,grid.size(),grid[0].size());
                    island++ ;
                }
            }
        }
        return island;
    }
};