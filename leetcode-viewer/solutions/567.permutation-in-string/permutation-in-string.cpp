class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> hash;
        
        for(char s:s1) {
            hash[s]++;
        }
        
        int count=s1.size();
        int i=0, j=0;
        
        while(i<s2.size()) {
            if(hash[s2[i++]]-->0) {
                count--;
            }
            while(count==0) {
                if(i-j==s1.size()) return true;
                if(hash[s2[j++]]++==0) count++;
            }
        }
        
        return false;
    }
};