class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        
        vector<int> first(nums.begin(),nums.end()-1);
        vector<int> second(nums.begin()+1,nums.end());
        
        return max(maxRob(first), maxRob(second));
        
        
    }
    
    int maxRob(vector<int>& nums) {
        int pre=0, pre_2=0;
    
        for(auto i:nums)
        {
            int tmp=pre_2+i;
            pre_2=pre;
            pre=max(tmp,pre);
        }

        return pre;
    }
    
};