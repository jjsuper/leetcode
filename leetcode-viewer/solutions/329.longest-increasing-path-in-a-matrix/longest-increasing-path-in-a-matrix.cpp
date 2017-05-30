class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=m? matrix[0].size(): 0;
        if(m==0 || n==0) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res=0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                res=max(res, dfs(matrix, i, j, dp));
            }
        }
        return res;
    }
private:
    vector<pair<int, int>> dirs={{1,0}, {-1,0}, {0,1}, {0,-1}};
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if(dp[i][j]) return dp[i][j];
        int m=matrix.size();
        int n=m? matrix[0].size(): 0;
        int res=1;
        
        for(auto dir : dirs) {
            int x=i+dir.first, y=j+dir.second;
            if(x<0 || x>=m || y<0 || y>=n || matrix[i][j] >= matrix[x][y]) continue;
            res=max(res, dfs(matrix, x, y, dp)+1);
        }
        
        dp[i][j]=res;
        
        return dp[i][j];
    }
};