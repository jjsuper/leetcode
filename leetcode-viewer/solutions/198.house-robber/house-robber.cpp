class Solution {
public:
    int rob(vector<int>& nums) {
        
    int pre = 0 , pre_2 = 0;
    for(int i=0;i<nums.size();i++)
       swap(pre,pre_2=max(pre_2+nums[i],pre));
    return pre;
        
        
    }
};