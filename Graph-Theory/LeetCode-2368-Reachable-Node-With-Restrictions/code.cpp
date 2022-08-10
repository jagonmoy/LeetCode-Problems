class Solution {
public:
    
    void dfs(int node,vector<vector<int>>& graph, vector<int>& state) {
        state[node] = 1 ;
        for ( int i = 0 ; i < graph[node].size() ; i++) {
            int childNode = graph[node][i];
            if (!state[childNode]) dfs(childNode,graph,state);
        }
    }
    
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph ;
        vector<int> state(n+5);
        for ( int i = 0 ; i < restricted.size() ; i++) state[restricted[i]] = 3 ;
        graph.resize(n+3);
        for ( int i = 0 ; i < edges.size() ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,graph,state);
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++) if (state[i] == 1) ans++ ;
        return ans;
    }
};