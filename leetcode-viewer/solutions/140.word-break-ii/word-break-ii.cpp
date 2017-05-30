class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> res;
        string cur="";
        
        int minlen=INT_MAX, maxlen=INT_MIN;
        
        for(string it : dict) {
            minlen=min(minlen, (int)it.size());
            maxlen=max(maxlen, (int)it.size());
        }
        
        vector<bool> dp(s.size()+1, 0);
        dp[s.size()]=1;
        
        for(int i=s.size()-minlen; i>-1; --i) {
            for(int len=minlen; len<=min(maxlen, (int)s.size()-i); ++len) {
                if(dp[i+len] && dict.count(s.substr(i, len))) {
                    dp[i]=1;
                    break;
                }
            }
        }
        
        if(dp[0]) dfs(s, dict, cur, res);
        return res;
    }
private:
    void dfs(string s, unordered_set<string>& dict, string cur, vector<string>& res) {
        if(s.empty()) res.push_back(cur.substr(0, cur.size()-1));
        
        for(int i=1; i<=s.size(); ++i) {
            if(dict.find(s.substr(0,i))!=dict.end()) {
                string scur=cur+s.substr(0,i)+" ";
                dfs(s.substr(i), dict, scur, res);
            }
        }
    }
    
    
    
};