class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        string res;
        
        for(char c : t) {
            hash[c]++;
        }
        
        int head=0, end=0, start=0, minlen=INT_MAX, count=t.size();
        
        while(end<s.size()) {
            if(hash[s[end++]]-->0) {
                count--;
            }
            while(count==0) {
                if(end-start<minlen) {
                    head=start;
                    minlen=end-start;
                }
                if(hash[s[start++]]++==0) {
                    count++;
                }
            }
            
        }
        
        return minlen==INT_MAX? "": s.substr(head, minlen);
        
    }
};