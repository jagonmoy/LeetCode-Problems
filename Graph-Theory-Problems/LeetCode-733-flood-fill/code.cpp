class Solution {
public:
  
    void dfs(vector<vector<int>>& image,vector<vector<int>>& visit,int row, int col, int rowMax, int colMax,int matchColor,int newColor) {
        if ( row >= rowMax || row < 0 || col >= colMax || col < 0 || visit[row][col] == 1 || image[row][col] != matchColor) return ;
        else {
            image[row][col] = newColor;
            visit[row][col] = 1 ;
        }
        int dirX[] = {1,-1,0,0};
        int dirY[] = {0,0,1,-1};
        for ( int i = 0 ; i < 4 ; i++)dfs(image,visit,row+dirX[i],col+dirY[i],rowMax,colMax,matchColor,newColor);
        return ;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> visit;
        visit.resize(image.size(), vector<int> (image[0].size(),0));
        dfs(image,visit,sr,sc,image.size(),image[0].size(),image[sr][sc],newColor);
        return image;
    }
};