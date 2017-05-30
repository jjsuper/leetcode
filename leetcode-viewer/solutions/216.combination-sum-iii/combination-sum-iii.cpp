class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       
        vector<vector<int>> res;
        vector<int> combination;
        
        combinationCal(k, n, res, combination, 1);
        
        return res;
    }
    
    void combinationCal(int k, int n, vector<vector<int>>& res, vector<int>& combination, int begin)
    {
        if(!n&&!k)
        {
            res.push_back(combination);
        }
        
        
        for(int i=begin; i<10 && i<=n && k>0; ++i)
        {
            combination.push_back(i);
            combinationCal(k-1, n-i, res, combination, i+1);
            combination.pop_back();
        }
        
    }
        

};