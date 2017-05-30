class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxlen=0;
        for(int begin=0; begin+k<=s.size();) {
            vector<int> cnt(26,0);
            int mask=0;
            int maxend=begin;
            for(int end=begin; end<s.size(); ++end) {
                int index=s[end]-'a';
                cnt[index]++;
                if(cnt[index]<k) mask |= (1<<index);
                else mask &= ~(1<<index);
                
                if(!mask) {
                    maxlen=max(maxlen, end-begin+1);
                    maxend=end;    
                }
            }
            begin=maxend+1;
        }
        
        return maxlen;
    }
};