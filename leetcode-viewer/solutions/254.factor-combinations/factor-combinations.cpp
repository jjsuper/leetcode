class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> cur;
        vector<vector<int>> res;
        helper(n, cur, res);
        return res;
    }
private:
    void helper(int n, vector<int>& cur, vector<vector<int>>& res) {
        int i=cur.empty()? 2: cur.back();
        for(; i<=n/i; ++i) {
            if(n%i==0) {
                cur.push_back(i);
                cur.push_back(n/i);
                res.push_back(cur);
                cur.pop_back();
                helper(n/i, cur, res);
                cur.pop_back();
            }
        }
    }
};