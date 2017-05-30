class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        
        int j=0;
        for(int i=1; i<nums.size(); ++i) {
            if(nums[i]!=nums[j]) {
                j++;
                swap(nums[i], nums[j]);
            }
        }
        return j+1;
    }
};