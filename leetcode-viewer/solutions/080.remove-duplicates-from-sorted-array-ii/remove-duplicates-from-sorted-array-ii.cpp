class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret=0;
        int pre=0;
        
        
        for(int i=0; i<nums.size(); ++i)
        {
            if(i==pre) ret++;
            else 
            {
                if(nums[i]==nums[pre] && i-pre==1) 
                {
                    nums[ret]=nums[i];
                    ret++;
                }
                if(nums[i]!=nums[pre])
                {
                    nums[ret]=nums[i];
                    ret++;
                    pre=i;
                }
            }
        }
        
        
        return ret;
    }
};