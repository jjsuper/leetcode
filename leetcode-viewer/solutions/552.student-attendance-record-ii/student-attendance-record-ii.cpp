class Solution {
public:
    int checkRecord(int n) {
        if(n==0) return 0;
        if(n==1) return 3;
        vector<long> dp(n+1, 0);
        dp[0]=1; dp[1]=1; dp[2]=2;
        for(int i=3; i<=n; ++i) {
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000007;
            //cout << dp[i] << endl;
        }
        
        int res=(dp[n]+dp[n-1]+dp[n-2])%1000000007;
        //cout << dp[n];
        for(int i=1; i<=n; ++i) {
            res+=(dp[i]*dp[n+1-i])%1000000007;
            res%=1000000007;
        }
        
        return res;
    }
};