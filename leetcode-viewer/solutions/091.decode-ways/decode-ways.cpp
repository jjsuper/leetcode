class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int cur=1;
        int pre=0;
        
        for(int i=s.size()-1; i>=0; --i) {
            if(s[i]=='0') {pre=cur; cur=0;}
            else if(s[i]=='1' || s[i]=='2' && s[i+1] < '7') {int tmp=cur; cur+=pre; pre=tmp;}
            else {pre=cur;}
        }
        
        return cur;
        
    }
};