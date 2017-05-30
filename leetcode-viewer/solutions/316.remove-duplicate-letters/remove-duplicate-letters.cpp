class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.empty()) return "";
        vector<int> cnt(26, 0);
        int pos=0;
        
        for(char c: s) cnt[c-'a']++;
        for(int i=0; i<s.size(); ++i) {
            if(s[i]<s[pos]) pos=i;
            if(--cnt[s[i]-'a']==0) break;
        }
        
        string news=s.substr(pos+1);
        cout << "before:  " <<news << endl;
        int i=0;
        while(i<news.size()) {
            if(news[i]==s[pos]) news.erase(i,1);
            else i++;
        }
        cout << s[pos]+news << endl;
        
        return s[pos]+removeDuplicateLetters(news);
    }
};