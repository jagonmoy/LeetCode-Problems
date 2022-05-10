class Solution {
public:
    
    void dfs1(vector<vector<int>>& grid, vector<vector<int>>& visit,int row,int col,int rowMax,int colMax,int& groupno,vector<vector<int>>& group) {
        if ( row == rowMax || row < 0 || col == colMax || col < 0 || visit[row][col] == 1 || grid[row][col] == 0) return ;
        else {
            visit[row][col] = 1 ;
            group[row][col] = groupno ;
        }
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,1,-1};
        for ( int i = 0 ; i < 4 ; i++) dfs1(grid,visit,row+dirX[i],col+dirY[i],rowMax,colMax,groupno,group);
        return ;
    }
    
      void dfs2(vector<vector<int>>& grid, vector<vector<int>>& visit,int row,int col,int rowMax,int colMax,vector<vector<int>>& group,set<int>& groupSet) {
        if ( row == rowMax || row < 0 || col == colMax || col < 0 || visit[row][col] == 1 || grid[row][col] == 0) return ;
        else {
            visit[row][col] = 1 ;
            groupSet.insert(group[row][col]);
        }
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,1,-1};
        for ( int i = 0 ; i < 4 ; i++) dfs2(grid,visit,row+dirX[i],col+dirY[i],rowMax,colMax,group,groupSet);
        return ;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector < vector < int> > visit1 ;
        visit1.resize(grid1.size(), vector <int> (grid1[0].size(),0));
        vector < vector < int> > visit2 ;
        visit2.resize(grid2.size(), vector <int> (grid2[0].size(),0));
        int rowMax1 = grid1.size();
        int rowMax2 = grid2.size();
        int colMax1 = grid1[0].size();
        int colMax2 = grid2[0].size();
        vector < vector < int> > group ;
        group.resize(rowMax1 , vector <int> (colMax1,0));
        int groupno = 1 ;
        for ( int i = 0 ; i < rowMax1 ; i++) {
            for ( int j = 0 ; j < colMax1 ; j++) {
                if ( visit1[i][j] == 0 && grid1[i][j] == 1) {
                    dfs1(grid1,visit1,i,j,rowMax1,colMax1,groupno,group);
                    groupno++ ;
                }
            }
        }
        
        set <int> groupSet;
        int subIsland = 0 ;
            
        for ( int i = 0 ; i < rowMax2 ; i++) {
            for ( int j = 0 ; j < colMax2 ; j++) {
                if ( visit2[i][j] == 0 && grid2[i][j] == 1) {
                    dfs2(grid2,visit2,i,j,rowMax2,colMax2,group,groupSet);
                    auto firstElement = groupSet.begin();
                    int islandNo = *firstElement;
                    if ( groupSet.size() == 1 && islandNo != 0) subIsland++ ; 
                    groupSet.clear();
                }
            }
        }
        
        return subIsland;
    }
};