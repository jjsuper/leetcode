class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves=0;
        int mid=nums[nums.size()/2];
        
        for(auto i:nums) {
            moves+=abs(i-mid);
        }
        
        return moves;
    }
};