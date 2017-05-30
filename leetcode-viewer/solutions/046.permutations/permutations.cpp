class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteCal(nums, res, 0);
        return res;
    }
    
    void permuteCal(vector<int>& nums, vector<vector<int>>& res, int begin)
    {
        if(begin==nums.size())
        {
            res.push_back(nums);
        }
        for(int i=begin; i<nums.size(); ++i)
        {
            swap(nums[begin],nums[i]);
            permuteCal(nums, res, begin+1);
            swap(nums[begin],nums[i]);
        }
    }

};