class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size();
        if(n==0) return 0;
        int k=costs[0].size();
        //if(k==1) return costs[0][0];
        vector<int> dp(k, 0);
        int min1, min2;
        
        for(int i=0; i<n; ++i) {
            int premin1=(i==0)?0: min1;
            int premin2=(i==0)?0: min2;
            min1=INT_MAX;
            min2=INT_MAX;
            for(int j=0; j<k; ++j) {
                if(dp[j]!=premin1) 
                    dp[j]=costs[i][j]+premin1;
                else 
                    dp[j]=costs[i][j]+premin2;
                  
                if(dp[j]>=min1) {
                    min2=min(min2, dp[j]);
                } 
                else {
                    min2=min1;
                    min1=dp[j];
                }   
            }
        }

        return min1;
    }
};