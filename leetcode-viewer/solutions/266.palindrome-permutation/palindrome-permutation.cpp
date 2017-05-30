class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> m;
        
        for(char c:s) m[c]++;
        
        bool odd=0;
        
        for(auto it=m.begin(); it!=m.end(); ++it) {
            if(it->second%2 && !odd) odd=1;
            else if(it->second%2 && odd) return false;
        }
        
        return true;
    }
};