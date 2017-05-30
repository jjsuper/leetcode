class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0;
        int minNum=nums[0];
        
        for(auto it: nums) {
            res+=it-minNum;
        }
        
        return res;
    }
};