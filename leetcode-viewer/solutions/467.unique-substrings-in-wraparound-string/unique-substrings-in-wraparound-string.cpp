class Solution {
public:
    int findSubstringInWraproundString(string p) {
        unordered_map<char, int> hash;
        int sum=0;
        int len=0;
        
        for(int i=0; i<p.size(); ++i) {
            if(i>0 && p[i-1]!=((p[i]-'a'+26-1)%26+'a')) len=0;
            len++;
            if(len>hash[p[i]]) {
                hash[p[i]]=len;
            }
        }
        
        for(auto it: hash) {
            sum+=it.second;
        }
        return sum;
    }
};