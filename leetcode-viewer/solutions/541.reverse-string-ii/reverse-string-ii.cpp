class Solution {
public:
    string reverseStr(string s, int k) {
        for(int left=0; left<s.size(); left+=2*k) 
            for(int i=left, j=min((int)s.size()-1, left+k-1); i<j; i++, j--)
                swap(s[i], s[j]);
        return s;
    }
};