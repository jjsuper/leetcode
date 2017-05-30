class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN;
        int sum=0;
        int minsum=0;
        for(auto n : nums) {
            sum+=n;
            res=max(res,sum-minsum);
            minsum=min(minsum, sum);
        }
        return res;
    }
    
};