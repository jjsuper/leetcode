class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(), rev.end());
        string tmp=s+"#"+rev;
        vector<int> T=kmp_table(tmp);
        string sub=s.substr(T[T.size()-1]);
        reverse(sub.begin(), sub.end());
        
        return sub+s;
    }
private:
    vector<int> kmp_table(string tmp) {
        vector<int> T(tmp.size(), 0);
        
        int i=1;
        int j=0;
        
        while(i<tmp.size()) {
            if(tmp[i]==tmp[j]) {
                j++;
                T[i]=j;
                i++;
            }
            else {
                if(j==0) {
                    i++;
                }
                else {
                    j=T[j-1];
                }
            }
        }

        return T;
    }
};