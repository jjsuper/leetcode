class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, unordered_set<string>> abbr2word;
        unordered_map<string, string> word2abbr;
        
        for(string word : dict) {
            if(word.size()<4) {
                word2abbr[word]=word;
            }
            else {
                string abbr = word[0]+to_string(word.size()-2)+word[word.size()-1];
                abbr2word[abbr].insert(word);
                word2abbr[word]=abbr;
            }
        }
        
        for(auto it : abbr2word) {
            if(it.second.size()>1) {
                unordered_map<string, unordered_set<string>> newabbr2word;
                unordered_set<string> needfix=it.second;
                int len=(*it.second.begin()).size();
                
                for(int i=2; i<=len && !needfix.empty(); ++i) {
                    if(i==len-2) {
                        for(string word : needfix) {
                            word2abbr[word]=word;
                        }
                        break;
                    }
                    
                    for(string word : needfix) {
                        string newabbr = word.substr(0, i) + to_string(len-i-1) + word[word.size()-1];
                        newabbr2word[newabbr].insert(word);
                    }
                    
                    needfix.clear();
                    for(auto newit : newabbr2word) {
                        if(newit.second.size()>1) {
                            for(string word : newit.second) {
                                needfix.insert(word);
                            }
                        }
                        else {
                            word2abbr[*newit.second.begin()]=newit.first;
                        }
                    }
                    newabbr2word.clear();
                    
                }
            }
        }
        
        
        
        vector<string> res;
        for(string word : dict) {
            res.push_back(word2abbr[word]);
        }
        return res;
    }
};