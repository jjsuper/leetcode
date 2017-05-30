class Solution {
public:
    bool isScramble(string s1, string s2) {
        int size=s1.size();
        if(size==0) return true;
        if(size==1) return s1==s2;
        vector<vector<vector<bool>>> dp(size+1, vector<vector<bool>>(size, vector<bool>(size, 0)));
        
        for(int i=0; i<size; ++i) 
            for(int j=0; j<size; ++j) {
                dp[1][i][j]=s1[i]==s2[j];
            }
        
        for(int len=2; len<=size; ++len) {
            for(int i=0; i<=size-len; ++i) {
                for(int j=0; j<=size-len; ++j) {
                    for(int k=1; k<len && !dp[len][i][j]; ++k) {
                        dp[len][i][j]=(dp[k][i][j]&&dp[len-k][i+k][j+k])||(dp[k][i+len-k][j]&&dp[len-k][i][j+k]);
                    }
                }
            }
        }
        
        return dp[size][0][0];
    }
};