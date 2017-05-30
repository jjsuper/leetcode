class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        //[index, [diff, count]]
        if(A.empty()) return 0;
        vector<unordered_map<int, int>> dp(A.size());
        int res=0;
        
        for(int i=0; i<A.size(); ++i) {
            for(int j=0; j<i; ++j) {
                long diff=(long)A[i]-A[j];
                if(diff>INT_MAX || diff<INT_MIN) continue;
                
                int dif=(int)diff;
                dp[i][dif] += 1;
                if(dp[j].find(dif) != dp[j].end()){
                    dp[i][dif] += dp[j][dif];
                    res += dp[j][dif];
                }
            }
        }
    
        return res;
    }
};