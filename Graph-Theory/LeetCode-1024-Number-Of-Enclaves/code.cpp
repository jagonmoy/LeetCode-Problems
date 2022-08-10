class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visit,int row,int col,int rowMax,int colMax,int& connectedComponent,bool& walkable) {
        if ( row == rowMax || row < 0 || col == colMax || col < 0 || visit[row][col] == 1 || grid[row][col] == 0) return ;
        else visit[row][col] = 1 ;
        connectedComponent++ ;
        if ( row == 0 || row == rowMax-1 || col == 0 || col == colMax-1) walkable = true ;
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,-1,1};
        for ( int i = 0 ; i < 4 ; i++) dfs(grid,visit,row+dirX[i],col+dirY[i],rowMax,colMax,connectedComponent,walkable);
        return;
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        vector < vector < int > > visit ;
        int rowMax = grid.size();
        int colMax = grid[0].size();
        visit.resize(rowMax , vector < int > (colMax,0));
        int totalEnclaves = 0 ;
        for ( int i = 0 ; i < rowMax ; i++) {
            for ( int j = 0 ; j < colMax ; j++) {
                if ( visit[i][j] == 0 && grid[i][j] == 1) {
                    int connectedComponent = 0 ;
                    bool walkable = false ;
         dfs(grid,visit,i,j,rowMax,colMax,connectedComponent,walkable);
                    if(!walkable) totalEnclaves += connectedComponent;
                }
            }
        }
        return totalEnclaves;
    }
};