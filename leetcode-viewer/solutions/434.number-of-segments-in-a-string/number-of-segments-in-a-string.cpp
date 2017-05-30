class Solution {
public:
    int countSegments(string s) {
        s=s + ' ';
        int cnt=0;
        for(int i=1; i<s.size(); ++i) {
            if(s[i]==' ' && s[i-1]!=' ') cnt++;
        }
        return cnt;
    }
};