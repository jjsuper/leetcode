class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(auto it: nums) {
            it=abs(it);
            if(nums[it-1]>0) nums[it-1]=-nums[it-1];
            else ans.push_back(it);
        }
        
        return ans;
    }
};