class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
        // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
        //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // f[0, ii] = 0; 0 times transation makes 0 profit
        // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
        if(prices.size()<2) return 0;
        
        
        //if k >= n/2, then you can make maximum number of transactions.
	if (k >=  prices.size()/2) {
		int maxPro = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i-1])
				maxPro += prices[i] - prices[i-1];
		}
		return maxPro;
	}
        
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        
        for(int i=1; i<=k; ++i) {
            int tmpMax=dp[i-1][0]-prices[0];
            for(int j=1; j<prices.size(); ++j) {
                dp[i][j]=max(dp[i][j-1], prices[j]+tmpMax);
                tmpMax=max(tmpMax, dp[i-1][j]-prices[j]);
            }
        }
        
        return dp[k][prices.size()-1];
    }
};