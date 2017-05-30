class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftToRm=0, rightToRm=0;
        unordered_set<string> res;
        
        for(char c:s) {
            if(c=='(') leftToRm++;
            if(c==')') {
                if(leftToRm>0) leftToRm--;
                else rightToRm++;
            }
        }
        
        helper(s, 0, leftToRm, rightToRm, 0, "", res);
        
        return vector<string>(res.begin(), res.end());
    }
private:
    void helper(string s, int index, int leftToRm, int rightToRm, int pair, string path, unordered_set<string>& res) {
        if(index==s.size()) {
            if(leftToRm==0 && rightToRm==0 && pair==0) 
                res.insert(path);
            return;
        }
        
        if(s[index]!='(' && s[index]!=')') 
            helper(s, index+1, leftToRm, rightToRm, pair, path+s[index], res);
        else if(s[index]=='(') {
            if(leftToRm>0) helper(s, index+1, leftToRm-1, rightToRm, pair, path, res);
            helper(s, index+1, leftToRm, rightToRm, pair+1, path+s[index], res);
        }
        else {
            if(rightToRm>0) helper(s, index+1, leftToRm, rightToRm-1, pair, path, res);
            if(pair>0) helper(s, index+1, leftToRm, rightToRm, pair-1, path+s[index], res);
        }
    }
};