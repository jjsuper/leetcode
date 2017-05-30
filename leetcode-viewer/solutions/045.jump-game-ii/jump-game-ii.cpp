class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0, curend=0, farest=0;
        
        for(int i=0; i<nums.size()-1; ++i) {
            farest=max(farest, i+nums[i]);
            if(i==curend) {
                curend=farest;
                jumps++;
            }
        }
        
        return jumps;
    }
};