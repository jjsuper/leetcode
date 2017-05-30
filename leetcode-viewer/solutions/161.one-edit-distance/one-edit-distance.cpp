class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int diff=s.size()-t.size();
        if(diff>1) return false;
        
        for(int i=0; i<min(s.size(), t.size()); i++) {
            if(s[i]!=t[i]) {
                return s.substr(i+(s.size()>=t.size()?1:0))==t.substr(i+(s.size()<=t.size()?1:0));
            }
        }
        
        return abs(diff)==1;
    }
};