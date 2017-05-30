class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto n: nums) sum+=n;
        if(sum&1) return false;
        int target=sum/2;
        vector<bool> dp(target+1, 0);
        dp[0]=1;
        for(auto n: nums) {
            for(int i=target; i>=n; i--) {
                dp[i] = dp[i] || dp[i-n];
            }
        }
        return dp[target];
    }
};