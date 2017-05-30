class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res=0;
        
        for(int i=0, j=0; i<nums.size(); ++i) {
            j=max(j, i+1); 
            while(j<nums.size() && nums[j]-nums[i]<k) ++j; 
            if(j<nums.size() && nums[j]-nums[i]==k) res++;
            while(i+1<nums.size() && nums[i]==nums[i+1]) ++i;
        }
        
        return res;
    }
};