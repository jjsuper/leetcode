class Solution {
public:
    bool isNumber(string s) {
        
        int idx=0;
        int num=0, pt=0;
        while(idx<s.size() && s[idx]==' ') idx++;
        if(s[idx]=='+' || s[idx]=='-') idx++;
        
        while(idx<s.size() && (isdigit(s[idx]) || s[idx]=='.')) {
            s[idx++]=='.'? pt++: num++;
        }
        if(num<1 || pt>1) return false;
        
        if(s[idx]=='e') {
            idx++;
            num=0;
            if(s[idx]=='+' || s[idx]=='-') idx++;
            while(idx<s.size() && isdigit(s[idx])) {
                num++;
                idx++;
            }
            
            if(num<1) return false;
        }
        
        while(idx<s.size() && s[idx]==' ') idx++;
        
        return idx==s.size();
    }
};