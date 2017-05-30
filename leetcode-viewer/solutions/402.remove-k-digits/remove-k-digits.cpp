class Solution {
public:
    string removeKdigits(string num, int k) {
        int digits=num.size()-k;
        string res(num.size(), '0');
        int top=0;
        
        for(int i=0; i<num.size(); ++i) {
            while(top>0 && res[top-1]>num[i] && k>0) {
                top--;
                k--;
            }
            res[top++]=num[i];
        }
        int idx=0;
        while(idx<digits && res[idx]=='0') idx++;
        
        
        return idx==digits? "0": res.substr(idx, digits-idx);
    }
};