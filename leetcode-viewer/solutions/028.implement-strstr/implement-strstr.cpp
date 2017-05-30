class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        
        for(int i=0; i+needle.size()<=haystack.size(); ++i) {
            bool foundNoMatch=false;
            for(int j=0; j<needle.size(); ++j) {
                if(haystack[i+j]!=needle[j]) {
                    foundNoMatch=true;
                    break;
                }
            }
            if(!foundNoMatch) {
                return i;   
            }
        }
        
        return -1;
    }
};