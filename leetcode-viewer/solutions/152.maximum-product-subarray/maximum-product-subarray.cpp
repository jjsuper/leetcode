class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int res=nums[0];
        int preMax=nums[0], preMin=nums[0];
        int curMax, curMin;
        
        for(int i=1; i<nums.size(); ++i) {
            curMax = max(max(preMax*nums[i], preMin*nums[i]), nums[i]);
            curMin = min(min(preMax*nums[i], preMin*nums[i]), nums[i]);
            preMax = curMax;
            preMin = curMin;
            res = max(res, curMax);
        }
        return res;
    }
};