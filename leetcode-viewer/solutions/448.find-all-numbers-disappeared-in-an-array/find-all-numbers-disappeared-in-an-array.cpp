class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(auto it: nums) {
            it=abs(it);
            if(nums[it-1]>0) nums[it-1]=-nums[it-1];
        }
        
        vector<int> ans;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i]>0) ans.push_back(i+1);
        }
        
        
        return ans;
    }
};