class Solution {
public:
    bool canJump(vector<int>& nums) {
 /*       if(nums.size()<=1) return true;
        if(nums.size()-1<=nums[0]) return true;
        
        for(int i=1; i<=nums[0]; ++i)
        {
            vector<int> Nnums(nums.begin()+i, nums.end());
            if(canJump(Nnums)) return true;
        }
        
        return false;*/
        int reach=0;
        int i;
        for(i=0; i<nums.size() && i<= reach; ++i )
        {
            reach = max(reach, i+nums[i]);
            
        }
        
        return i==nums.size();
    }
};

