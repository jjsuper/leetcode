class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> res;
        helper(s, 0, path, res);
        return res;
    }    
        
private:
    void helper(string s, int index, vector<string>& path, vector<vector<string>>& res) {
        if(index==s.size()) {
            res.push_back(path);
            return;    
        }
        
        for(int i=index; i<s.size(); ++i) {
            if(isPalindrome(s.substr(index, i-index+1))) {
                path.push_back(s.substr(index, i-index+1));
                helper(s, i+1, path, res);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        for(int i=0; i<s.size()/2; ++i) {
            if(s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }
};