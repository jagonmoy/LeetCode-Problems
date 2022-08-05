class Solution {
public:
    
    void backtrack(vector<int>& candidates,int n, int target,vector<int>singleCombination,vector<vector<int>>& result) {
       if ( target == 0) {
           result.push_back(singleCombination);
           return ;
       }
       if ( n == 0) return ;
       bool taken = false;
       if (target - candidates[n-1] >= 0) {
           singleCombination.push_back(candidates[n-1]);
           backtrack(candidates,n,target-candidates[n-1],singleCombination,result);
           taken = true ;
       }
       if (taken) singleCombination.pop_back();
       backtrack(candidates,n-1,target,singleCombination,result);
       return ;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>singleCombination;
        vector<vector<int>> result;
        backtrack(candidates,candidates.size(),target,singleCombination,result);
        return result;
        
    }
};