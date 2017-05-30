class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n=words[0].size();
        vector<vector<string>> res;
        vector<string> cur;
        
        for(auto word: words) {
            for(int i=0; i<n; ++i)
                hash[word.substr(0, i)].push_back(word);
        }    
        
        build(res, cur, 0, n);
        
        return res;
    }
private:
    unordered_map<string, vector<string>> hash;
    
    void build(vector<vector<string>>& res, vector<string>& cur, int i, int n) {
        if(i==n) {
            res.push_back(cur);
            return;
        }
        string prefix;
        for(int j=0; j<i; ++j) {
            prefix=prefix+cur[j][i];
        }
        for(string word: hash[prefix]) {
            cur.push_back(word);
            build(res, cur, i+1, n);
            cur.pop_back();
        }
    }
};