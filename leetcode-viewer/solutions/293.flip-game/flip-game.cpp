class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if(s.size()<2) return res;
        
        for(int i=0; i<s.size()-1; ++i) {
            if(s[i]=='+' && s[i+1]=='+') {
                string tmp=s.substr(0, i)+"--"+s.substr(i+2);
                res.push_back(tmp);
            }
        }
        
        return res;
    }
};