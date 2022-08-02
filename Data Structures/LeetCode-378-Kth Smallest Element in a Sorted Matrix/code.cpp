class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue < pair<int,pair<int,int>> , vector < pair <int,pair<int,int>> > , greater< pair<int,pair<int,int> > > > pq ;
        pq.push({matrix[0][0],{0,0}});
        
        long long ans ;
        int n = matrix[0].size() - 1 ;
        map<pair<int,int>, int> mymap;
        while(k) {
            pair<int,pair<int,int>> element = pq.top();
            pq.pop();
            ans = element.first;
            int x = element.second.first;
            int y = element.second.second;
            if ( y+1 <= n && !mymap[{x,y+1}]) {
                pq.push({matrix[x][y+1],{x,y+1}});
                mymap[{x,y+1}] = 1 ;
            }
            if ( x+1 <= n && !mymap[{x+1,y}]) {
                pq.push({matrix[x+1][y],{x+1,y}});
                mymap[{x+1,y}] = 1 ;
            }
            k-- ;
        }
        return ans;
    }
};