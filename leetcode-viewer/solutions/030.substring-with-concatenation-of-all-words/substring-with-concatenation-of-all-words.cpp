class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> count;
        for(string word: words) count[word]++;
        int len=words[0].size(), num=words.size();
        vector<int> res;
        
        for(int i=0; i<s.size()-len*num+1; ++i) {
            unordered_map<string, int> seen;
            int j=0;
            for(; j<num; ++j) {
                string tmp=s.substr(i+j*len, len);
                if(count.find(tmp)!=count.end()) {
                    seen[tmp]++;
                    if(seen[tmp]>count[tmp])
                        break;
                }
                else break;
            }
            if(j==num) res.push_back(i);
        }
        
        return res;
    }
};