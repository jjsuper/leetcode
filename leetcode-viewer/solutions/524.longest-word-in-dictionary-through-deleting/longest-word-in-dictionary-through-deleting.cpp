class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        
        for(int i=0; i<d.size(); ++i) {
            int pj=0;
            for(int pi=0; pi<s.size() && pj<d[i].size(); ++pi) {
                pj += s[pi]==d[i][pj];
            }
            if(pj==d[i].size() && (res.size() < pj || (res.size()==pj && res>d[i])))
                res=d[i];
        }
        return res;
    }
};