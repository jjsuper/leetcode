class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n<4) return res;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; ++i) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            
            for(int j=i+1; j<n; ++j) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                
                int left=j+1, right=n-1;
                while(left<right) {
                    int sum=target-nums[i]-nums[j];
                    if(nums[left]+nums[right]>sum) right--;
                    else if(nums[left]+nums[right]<sum) left++;
                    else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;
                        while(nums[left]==nums[left-1]&&left<right) left++;
                        while(nums[right]==nums[right+1]&&left<right) right--;
                    }
                }   
            }
        }
        
        
        
        
        return res;
    }
};