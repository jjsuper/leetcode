class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(), start=-1, end=-1, minn=nums[n-1], maxn=nums[0];
        
        for(int i=0; i<nums.size(); ++i) {
            minn=min(minn, nums[n-1-i]);
            maxn=max(maxn, nums[i]);
            if(nums[i] < maxn) end=i;
            if(nums[n-1-i] > minn) start=n-1-i;
        }
        
        
        return start<end? end-start+1: 0;
    }
};