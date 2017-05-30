class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationCal(candidates, target, res, combination, 0);
        return res;
    }
    
    void combinationCal(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combination, int begin)
    {
        if(!target)
        {
            res.push_back(combination);
        }
        for(int i=begin; i<candidates.size() && candidates[i]<=target; ++i)
        if(i==begin || candidates[i]!=candidates[i-1])
        {
            combination.push_back(candidates[i]);
            combinationCal(candidates, target-candidates[i], res, combination, i+1);
            combination.pop_back();
        }
    }
};