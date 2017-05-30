class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i=0; i<words.size(); ++i) {
            hash[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res=INT_MAX;
        int idx1=0, idx2=0;
        
        while(idx1<hash[word1].size() && idx2<hash[word2].size()) {
            int tmp=abs(hash[word1][idx1]-hash[word2][idx2]);
            res=min(res,tmp);
            if(hash[word1][idx1]<hash[word2][idx2]) {
                idx1++;
            }
            else {
                idx2++;
            }
            
        }
        
        return res;
    }
private:
    unordered_map<string, vector<int>> hash;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */