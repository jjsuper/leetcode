class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> comb;
        int begin=1;
        recursion(n, k, 1, comb, ret);
        return ret;
    }
    
    
    
    
    void recursion(int n, int k, int begin, vector<int>& comb, vector<vector<int>>& ret)
    {
        if(k==0)
        {
            ret.push_back(comb);
            return;
        }
        for(int i=begin; i<=n; ++i)
        {
            comb.push_back(i);
            recursion(n, k-1, i+1, comb, ret);
            comb.pop_back();
        }
        
    }

};