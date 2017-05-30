class Solution {
public:
    int strongPasswordChecker(string s) {
        int deleteTarget=max(0, (int)s.size()-20), addTarget=max(0, 6-(int)s.size());
        int toAdd=0, toDelete=0, toReplace=0, needUpper=1, needLower=1, needDigit=1;
        
        ///////////////////////////////////
        // For cases of s.length() <= 20 //
        ///////////////////////////////////
        for(int l=0, r=0; r<s.size(); ++r) {
            if(isupper(s[r])) needUpper=0;
            if(islower(s[r])) needLower=0;
            if(isdigit(s[r])) needDigit=0;
            
             // if it's a three-letter window
             // found a three-repeating substr
             // insert letter to break repetition if possible
             // replace current word to avoid three repeating chars
             // keep the window with no more than 3 letters
            if(r-l==2) {
                if(s[r]==s[r-1]&&s[r-1]==s[l]) {
                    if(toAdd < addTarget) {
                        toAdd++;
                        l=r;
                    }
                    else {
                        toReplace++;
                        l=r+1;
                    }
                }
                else {
                    l++;
                }
            }
            
        }
        if(s.size()<=20) return max(addTarget+toReplace, needUpper+needLower+needDigit);
        
       
        //////////////////////////////////
        // For cases of s.length() > 20 //
        //////////////////////////////////
        toReplace=0;
         // reset toReplace
         // to record repetitions with (length % 3) == 0, 1 or 2
         // record all repetion frequencies
         // we only care about repetions with length >= 3
        vector<unordered_map<int, int>> hash(3);
        for(int l=0, r=0, len; r<=s.size(); ++r) {
            if(r==s.size() || s[l]!=s[r]) {
                if((len=r-l) > 2) hash[len%3][len]++;
                l=r;
            }
        }
   
         /*
            Use deletions to minimize replacements, following below orders:
            (1) Try to delete one letter from repetitions with (length % 3) == 0. Each deletion decreases replacement by 1
            (2) Try to delete two letters from repetitions with (length % 3) == 1. Each deletion decreases repalcement by 1
            (3) Try to delete multiple of three letters from repetions with (length % 3) == 2. Each deletion (of three 
            letters) decreases repalcements by 1
        */
        
    // dec is the number of repetitions we'll delete from
    // update number of repetitions left
    // after letters deleted, it fits in the group where (length % 3) == 2
    // record number of replacements needed
    // note if len is the length of repetition, we need (len / 3) number of replacements
        
        
        for(int i=0; i<3; ++i) {
            for(auto it : hash[i]) {
                if(i<2) {
                    int numLetter=i+1; 
                    int dec=min(it.second, (deleteTarget- toDelete)/numLetter);
                    toDelete += dec*numLetter;
                    it.second -= dec;
                    
                    if(it.first-numLetter>2) {
                        hash[2][it.first-numLetter] += dec;
                    }
                }
                
                toReplace+= (it.second)*(it.first/3);
            }
        }
        
        int dec=(deleteTarget-toDelete)/3;
        toReplace-=dec;
        toDelete-=dec*3;
          
         // try to delete multiple of three letters as many as possible
        return deleteTarget+max(toReplace, needUpper+needLower+needDigit);
        
    }
};