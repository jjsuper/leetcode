class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> resset;
        vector<int> cur;
        helper(nums, 0, cur, resset);
        return vector<vector<int>>(resset.begin(), resset.end());
    }
private:
    void helper(vector<int>& nums, int index, vector<int>& cur, set<vector<int>>& res) {
        if(cur.size()>1) res.insert(cur);
        
        for(int i=index; i<nums.size(); ++i) {
            if(cur.size()==0 || nums[i]>=cur.back()) {
                cur.push_back(nums[i]);
                helper(nums, i+1, cur, res);
                cur.pop_back();
            }
        }
    }
    
    
};