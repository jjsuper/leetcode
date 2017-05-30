class Solution {
public:
    bool canWin(string s) {
        if(s.size()<2) return false;
        for(int i=0; i<s.size()-1; ++i) {
            if(s[i]=='+' && s[i+1]=='+') {
                s[i]='-'; s[i+1]='-';
                bool wins=!canWin(s);
                s[i]='+'; s[i+1]='+';
                if(wins) return true;
            }
        }
        return false;
    }
};