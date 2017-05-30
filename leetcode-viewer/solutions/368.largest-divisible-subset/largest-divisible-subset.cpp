class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        
        /*
        
        The key concept here is:
Given a set of integers that satisfies the property that each pair of integers inside the set are mutually divisible, for a new integer S, S can be placed into the set as long as it can divide the smallest number of the set or is divisible by the largest number of the set.

For example, let's say we have a set P = { 4, 8, 16 }, P satisfies the divisible condition. Now consider a new number 2, it can divide the smallest number 4, so it can be placed into the set; similarly, 32 can be divided by 16, the biggest number in P, it can also placed into P.
        
        
        
        */
        sort(nums.begin(), nums.end());
        
        vector<int> dp(nums.size(), 0);
        vector<int> next(nums.size(), 0);
        int maxn=0;
        int mini=0;
        
        
        for(int i=nums.size()-1; i>-1; --i) {
            for(int j=i; j<nums.size(); j++) {
                if(nums[j]%nums[i]==0 && dp[i]<1+dp[j]) {
                    dp[i]=dp[j]+1;
                    next[i]=j;
                    if(dp[i]>maxn) {
                        maxn=dp[i];
                        mini=i;
                    }
                }    
            }
        }
        
        
        vector<int> res;
        
        for(int i=0; i<maxn; ++i) {
            res.push_back(nums[mini]);
            mini=next[mini];
        }
        
        
        return res;
    }
};