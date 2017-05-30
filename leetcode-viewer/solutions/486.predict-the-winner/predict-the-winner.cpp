class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()%2==0) return true;
        
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        
        
        return 2*calculate(nums, dp, 0, nums.size()-1) >= accumulate(nums.begin(), nums.end(), 0);
    }
    
    int calculate(vector<int>& nums, vector<vector<int>>& dp, int i, int j) {
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        
        return max((min(calculate(nums, dp, i+1, j-1), calculate(nums, dp, i+2, j))+nums[i]), (min(calculate(nums, dp, i+1, j-1), calculate(nums, dp, i, j-2))+nums[j]));
    }
    
    
};