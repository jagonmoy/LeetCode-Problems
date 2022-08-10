class Solution {
public:
    
    bool match(int index,vector<int>& nums,int elements) {
        if( elements == 2) { 
             if (index+1 < nums.size() && nums[index] == nums[index+1] ) return true ;
             else return false ;
        }
        else {
            if (index+2 < nums.size() && nums[index] == nums[index+1] && nums[index+1] == nums[index+2] ) return true ;
            else if (index+2 < nums.size() && nums[index]+1 == nums[index+1] && nums[index+1]+1 == nums[index+2]) return true ;
            else return false ;
        }
    }
    
    bool partitionCheck(int index,vector<vector<int>>& dp,vector<int>& nums,int elements) {
        if (!match(index,nums,elements)) return false ;
        if ( index + elements == nums.size()) return true ;
        if ( dp[index][elements] != -1) return dp[index][elements];
        return dp[index][elements] = partitionCheck(index+elements,dp,nums,2) || partitionCheck(index+elements,dp,nums,3);
    }
    
    bool validPartition(vector<int>& nums) {
        vector < vector<int>> dp(nums.size()+2, vector<int> (4,-1));
        return partitionCheck(0,dp,nums,2) || partitionCheck(0,dp,nums,3);
        
    }
};