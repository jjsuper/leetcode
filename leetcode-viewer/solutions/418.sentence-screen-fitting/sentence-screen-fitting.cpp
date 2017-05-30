class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n=sentence.size();
        vector<int> dp(n);
        
        for(int i=0, prev=0, len=0; i<sentence.size(); ++i) {
            if(i && len>0) len -= (sentence[i-1].size()+1);
            while(len+sentence[prev%n].size()<=cols) len+=sentence[prev++%n].size()+1;
            dp[i]=prev;
        }
        int cnt=0;
        for(int i=0, k=0; i<rows; ++i) {
            cnt+=dp[k]-k;
            k=dp[k]%n;
        }
        return cnt/n;
    }
};