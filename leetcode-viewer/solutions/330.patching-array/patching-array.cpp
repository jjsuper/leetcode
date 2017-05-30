class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long maxNum=0;
        int i=0;
        int cnt=0;
        while(maxNum<n)
        {
            if(i<nums.size() && nums[i]<=maxNum+1)
            {
                maxNum+=nums[i];
                i++;
            }
            else
            {
                cnt++;
                maxNum+=maxNum+1;
            }
        }
        
        
        
        
        return cnt;
        
        
    }
};