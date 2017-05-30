class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> hash;
        int start=0, count=0, len=0;
        
        for(int i=0; i<s.size(); ++i) {
            hash[s[i]]++;     
            if(hash[s[i]]==1) {
                count++;
                while(count>k) {
                    hash[s[start]]--;
                    if(hash[s[start]]==0) count--;
                    start++;
                }
            }
            len=max(len, i-start+1);
        }
        return len;
    }
};