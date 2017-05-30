class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prev=-1;
        int prevn=0;
        int res=0;
        
        for(int i=0; i<=nums.size(); ++i) {
            if(!nums[i]||i==nums.size()) {
                int currn=i-prev-1;
                prev=i;
                res=max(res, currn+prevn+1);
                prevn=currn;
            }
        }
        
        return res>nums.size()? nums.size(): res;
    }
};