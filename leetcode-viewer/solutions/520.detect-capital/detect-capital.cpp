class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()<2) return true;
        
        bool cap1=word[0]>='A' && word[0]<='Z';
        bool cap2=word[1]>='A' && word[1]<='Z';
        
        cout << cap1 << cap2;
        if(!cap1 && cap2) return false;
        
        for(int i=2; i<word.size(); ++i) {
            if(!cap1 && word[i]>='A' && word[i]<='Z') return false;
            else if(cap2 && word[i]>='a' && word[i]<='z') return false;
            else if(!cap2 && word[i]>='A' && word[i]<='Z') return false;
        }
        
        return true;
    }
};