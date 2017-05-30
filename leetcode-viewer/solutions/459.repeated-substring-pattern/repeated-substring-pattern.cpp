class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int i=1, j=0, n=str.size();
        vector<int> kmp(n+1, 0);
        
        while(i<n) {
            if(str[i]==str[j]) kmp[++i]=++j;
            else if (j==0) i++;
            else j=kmp[j];
        }
        
        
        return kmp[n] && ( kmp[n]%(n-kmp[n])==0);
    }
};