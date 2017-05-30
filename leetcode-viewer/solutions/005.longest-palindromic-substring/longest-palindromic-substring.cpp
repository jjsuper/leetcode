class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()||s.size()<2) return s;
        int min_start=0, max_len=1;
        int i=0;
        
        while(i<s.size()) {
            if(s.size()-i<=max_len/2) break;
            int k=i, j=i;
            while(k<s.size()-1 && s[k+1]==s[k]) ++k;
            i=k+1;
            while(k<s.size()-1 && j>0 && s[k+1]==s[j-1]) {
                k++;
                j--;
            }
            if(k-j+1>max_len) {
                max_len=k-j+1;
                min_start=j;
            }
        }
        
        return s.substr(min_start, max_len);
    }
};