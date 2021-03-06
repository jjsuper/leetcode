class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
        // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
        //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // f[0, ii] = 0; 0 times transation makes 0 profit
        // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
        if(prices.empty()) return 0;
        int k=2, maxProf=0;
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        
        for(int i=1; i<=k; ++i) {
            int tmpMax=dp[i-1][0]-prices[0];
            for(int j=1; j<prices.size(); ++j) {
                dp[i][j]=max(dp[i][j-1], prices[j]+tmpMax);
                tmpMax=max(tmpMax, dp[i-1][j]-prices[j]);
                maxProf=max(dp[i][j], maxProf);
            }
        }
        
        return maxProf;
    }
};