class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        
        for(auto word : words) {
            if(isConcatenate(word, s)) {
                res.push_back(word);
            }
        }
        
        
        return res;
    }
    
    bool isConcatenate(string word, unordered_set<string>& s) {
        if(word.empty()) return 0;
        bool dp[word.size()+1]={0};
        dp[0]=1;
        
        for(int i=1; i<=word.size(); i++) {
            for(int j=i-1; j>=0; --j) {
                if(dp[j] && s.count(word.substr(j, i-j)) && i-j<word.size()) {
                    dp[i]=1;
                    break;
                }
            }
        }
        
        return dp[word.size()];
    }
    
    
};