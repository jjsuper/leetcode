class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        
        for(int i=1; i<nums.size(); ++i) {
            res[i]=nums[i-1]*res[i-1];
        }
        int tmp=1;
        
        for(int i=nums.size()-2; i>-1; --i) {
            tmp*=nums[i+1];
            res[i]*=tmp;
        }
        
        return res;
    }
};