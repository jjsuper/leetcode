class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        stack<char> key;
        
        for(int i=0; i<S.size(); ++i) {
            if(S[i]=='-') continue;
            if(S[i]>='a'&&S[i]<='z') key.push(S[i]-'a'+'A');
            else key.push(S[i]);
        }
        
        int cnt=K;
        string res="";
        while(!key.empty()) {
            char cur=key.top();
            key.pop();
            if(!cnt) {
                cnt=K;
                res='-'+res;
            }
            res=cur+res;
            cnt--;
        }
        
        
        
        return res;
    }
};