class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return "";
        int begin =0;
        
        for(int i=0; i<s.size(); ++i) {
            if(s[i]==' ') {
                reverse(s.begin()+begin, s.begin()+i);
                begin=i+1;
            }
        }
        
        reverse(s.begin()+begin, s.end());
        
        return s;
    }
};