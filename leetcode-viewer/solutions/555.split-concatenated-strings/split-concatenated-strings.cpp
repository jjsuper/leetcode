class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string s;
        for(int i=0; i<strs.size(); ++i) {
            string tmp=strs[i];
            reverse(tmp.begin(), tmp.end());
            //strs[i] = tmp > strs[i]? tmp: strs[i];
            s+= max(strs[i], tmp);
        }
        
        string res=s;
        
        for(int i=0, j=0; i<strs.size(); j+=strs[i++].size()) {
            string body=s.substr(j+strs[i].size()) + s.substr(0, j);
            
            string p1=strs[i];
            string p2=strs[i];
            reverse(p2.begin(), p2.end());
            
            for(int k=0; k<strs[i].size(); ++k) {
                res=max(res, p1.substr(k)+body+p1.substr(0,k));
                res=max(res, p2.substr(k)+body+p2.substr(0,k));
            }
        }
        
        
        
        return res;
    }
};