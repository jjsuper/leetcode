class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4||nums.empty()) return false;
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%4) return false;
        vector<int> sums(4,0);
        return dfs(nums, sums, 0, sum/4);
    }
private:
    bool dfs(vector<int>& nums, vector<int>& sums, int index, int target) {
        if(index==nums.size()) 
            if(sums[0]==sums[1] && sums[1]==sums[2] && sums[2]==target)
                return true;
            else 
                return false;
        
        for(int i=0; i<4; ++i) {
            if(sums[i]+nums[index]>target) continue;
            sums[i]+=nums[index];
            if(dfs(nums, sums, index+1, target)) return true;
            sums[i]-=nums[index];
        }
        
        
        
        return false;
    }
    
    
};