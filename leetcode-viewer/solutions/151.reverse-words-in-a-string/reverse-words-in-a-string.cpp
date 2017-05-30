class Solution {
public:
    void reverseWords(string &s) {
        int i=0, j=0, k=0;
        int wordcount=0;
        
        while(true) {
            while(i<s.size()&&s[i]==' ') i++;
            if(i==s.size()) break;
            if(wordcount) s[j++]=' ';
            k=j;
            while(i<s.size()&&s[i]!=' ') s[j++]=s[i++];
            reverse(s, k, j-1);
            wordcount++;
        }
        
        s.resize(j);
        reverse(s, 0, j-1);
        
    }
private:
    void reverse(string& s, int i, int j) {
        while(i<j) {
            swap(s[i++], s[j--]);
        }
    }
};