class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int total=0;
        for(auto num: nums) {total+=num;}
        
        int target=total+S;
        if(target%2 || total<S) return 0;
        
        target/=2;
        return dp(nums, target);
    }
private:
    int dp(vector<int>& nums, int target) {
        vector<int> cnt(target+1,0);
        cnt[0]=1;
        
        for(auto num: nums) {
            for(int i=target; i>=num; --i)
                cnt[i]+=cnt[i-num];
        }
        
        return cnt[target];
    }
};