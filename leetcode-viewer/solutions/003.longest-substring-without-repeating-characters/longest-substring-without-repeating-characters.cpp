class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        map<char, int> hash;
        int maxlen=0;
        
        for(int i=0, j=0; i<s.size(); ++i) {
            if(hash.find(s[i])!=hash.end()) {
                j=max(j, hash[s[i]]+1);
            }
            hash[s[i]]=i;
            maxlen=max(maxlen, i-j+1);
        }
        
        return maxlen;
    }
};