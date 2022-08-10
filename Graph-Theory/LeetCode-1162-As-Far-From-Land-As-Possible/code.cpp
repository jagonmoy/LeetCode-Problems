class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
       int rowMax = grid.size();
       int colMax = grid[0].size();
       queue<pair<int,int>> bfsQ;
       int dirX[] = {-1,1,0,0};
       int dirY[] = {0,0,-1,1};
        
       vector<vector<int>>dis ;
       dis.resize(rowMax,vector<int>(colMax,0));
       vector<vector<int>>visit ;
       visit.resize(rowMax,vector<int>(colMax,0));
        
       for ( int i = 0 ; i < rowMax ; i++) {
           for ( int j = 0 ; j < colMax ; j++) {
               if ( grid[i][j] == 1) {
                   bfsQ.push({i,j});
                   visit[i][j] = 1 ;
               }
           }
       }
       int maxRes = -1 ;
       while(!bfsQ.empty()){
           vector<pair<int,int>> stepVector ; 
           while(!bfsQ.empty()) {
               stepVector.push_back(bfsQ.front());
               bfsQ.pop();
           }
           for (int i = 0 ; i < stepVector.size() ; i++) {
               int x = stepVector[i].first ;
               int y = stepVector[i].second;
               for ( int j = 0 ; j < 4 ; j++) {
                   int adjX = x + dirX[j];
                   int adjY = y + dirY[j];
                   if ( adjX < rowMax && adjX >= 0 && adjY < colMax && adjY >= 0 && visit[adjX][adjY] == 0)  {
                       visit[adjX][adjY] = 1 ;
                       dis[adjX][adjY] = dis[x][y]+1 ;
                       maxRes = max(maxRes,dis[adjX][adjY]);
                       bfsQ.push({adjX,adjY});
                   }
               }
           }
       }
       return maxRes;
        
    }
};