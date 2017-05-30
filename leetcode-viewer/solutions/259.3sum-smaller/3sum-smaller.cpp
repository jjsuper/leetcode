class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans=0;
        if(nums.size()<3) return ans;
        
        for(int i=0; i<nums.size()-2; i++) {
            if(nums[i]+nums[i+1]+nums[i+2]>=target) break;
            int j=i+1, k=nums.size()-1;
            while(j<k) {
                while(j<k&&nums[i]+nums[j]+nums[k]>=target) k--;
                ans+=k-j;
                j++;
            }
        }
        
        
        
        return ans;
    }
};