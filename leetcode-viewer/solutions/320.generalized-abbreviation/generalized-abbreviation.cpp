class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        //if(word.empty()) return res;
        
        for(int i=0; i<pow(2, word.size()); ++i) {
            int mask=1;
            string cur="";
            int zero=0;
            
            for(int j=word.size()-1; j>-1; --j) {
                if(mask&i) {
                    if(!zero) cur=word[j]+cur;
                    else {
                        cur=word[j]+to_string(zero)+cur;
                        zero=0;
                    }
                }  
                else {
                    zero++;
                }
                mask=mask<<1;
            }
            if(zero) cur=to_string(zero)+cur;
            res.push_back(cur);
        }
        
        return res;
    }
};