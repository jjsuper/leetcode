class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26,0);
        int start=0, maxcnt=0, maxlen=0;
        for(int end=0; end<s.size(); ++end) {
            cnt[s[end]-'A']++;
            maxcnt=max(maxcnt, cnt[s[end]-'A']);
            if(end-start-maxcnt+1>k) {
                cnt[s[start]-'A']--;
                start++;
            }
            maxlen=max(maxlen, end-start+1);
        }
        return maxlen;
    }
};