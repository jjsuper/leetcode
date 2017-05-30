class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m=ring.size();
        int n=key.size();
        int dp[n+1][m]={0};
        
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<m; ++j) {
                dp[i][j]=INT_MAX;
                for(int k=0; k<m; ++k) {
                    if(ring[k]==key[i]) {
                        int diff=abs(j-k);
                        int step=min(diff, m-diff);
                        dp[i][j]=min(dp[i][j], step+dp[i+1][k]);
                    }
                }
            }
        }
        
        return dp[0][0]+n;
    }
};