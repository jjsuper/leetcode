class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m][n-1]=1;
        dp[m-1][n]=1;
        
        for(int i=m-1; i>-1; --i) {
            for(int j=n-1; j>-1; --j) {
                int need=min(dp[i+1][j], dp[i][j+1])-dungeon[i][j];
                dp[i][j] = need>0? need: 1; 
            }
        }
        
        return dp[0][0];
    }
};