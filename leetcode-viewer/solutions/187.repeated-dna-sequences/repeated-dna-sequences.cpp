class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> hash;
        unordered_set<string> res;
        
        
        for(int i=0; i+10<=s.size(); ++i) {
            int tmp=0;
            for(int j=i; j<i+10; ++j) {
                tmp<<=2;
                if(s[j]=='C') tmp+=1; 
                else if(s[j]=='G') tmp+=2;
                else if(s[j]=='T') tmp+=3;
            }
            if(hash.count(tmp)>0) res.insert(s.substr(i, 10));
            hash.insert(tmp);
        }
        
        
        return vector<string>(res.begin(), res.end());
    }
};