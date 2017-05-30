class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(wordDict.empty()) return false;
        if(s.empty()) return true;
        
        vector<bool> dp(s.size()+1, 0);
        dp[0]=1;
        
        for(int i=1; i<=s.size(); ++i) {
            for(int j=i-1; j>=0; --j) {
                if(dp[j]) {
                    string word=s.substr(j, i-j);
                    if(wordDict.find(word)!=wordDict.end()) {
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};