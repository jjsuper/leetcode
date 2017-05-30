class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size()) return false;
        
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, 0));
        
        for(int i=0; i<dp.size(); ++i){
            for(int j=0; j<dp[0].size(); ++j) {
                if(i==0 && j==0) dp[0][0]=1;
                else if(i==0) dp[0][j]=dp[0][j-1] && s2[j-1]==s3[j-1];
                else if(j==0) dp[i][0]=dp[i-1][0] && s1[i-1]==s3[i-1];
                else dp[i][j]=(dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        
        
        return dp[s1.size()][s2.size()];
    }
};