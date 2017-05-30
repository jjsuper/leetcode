class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m=M.size();
        int n=m? M[0].size(): 0;
        if(m==0 || n==0) return 0;
        int res=0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4,0)));
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(M[i][j]==1) {
                    for(int k=0; k<4; ++k) dp[i][j][k]=1;
                    
                    if(i>0 && M[i-1][j]==1) dp[i][j][0]+=dp[i-1][j][0];
                    if(j>0 && M[i][j-1]==1) dp[i][j][1]+=dp[i][j-1][1];
                    if(i>0 && j>0 && M[i-1][j-1]==1) dp[i][j][2]+=dp[i-1][j-1][2];
                    if(i>0 && j+1<n && M[i-1][j+1]==1) dp[i][j][3]+=dp[i-1][j+1][3];
                    
                    res=max(res, max(dp[i][j][0], dp[i][j][1]));
                    res=max(res, max(dp[i][j][2], dp[i][j][3]));
                }
            }
        }
        return res;
    }
};