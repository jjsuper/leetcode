class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> cur;
        set<vector<int>> res;
        helper(nums, cur, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
private:
    void helper(vector<int>& n, vector<int>& cur, set<vector<int>>& res) {
        if(n.empty()) {
            res.insert(cur);
            return;
        }
        
        for(int i=0; i<n.size(); ++i) {
            int tmp=n[i];
            cur.push_back(n[i]);
            n.erase(n.begin()+i);
            helper(n, cur, res);
            n.insert(n.begin()+i,tmp);
            cur.pop_back();
        }
    }
    
};