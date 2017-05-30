class Solution {
public:
    bool isAnagram(string s, string t) {
        /*sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
        */
        int charArr[26] = {0};

        for(int i=0;i<s.size();i++){
            charArr[(int(s[i])-97)]++;
        }
        for(int j=0;j<t.size();j++){
            charArr[(int(t[j])-97)]--;
        }
        for(int k=0;k<26;k++){
            if(charArr[k] != 0){
                return false;
            }
        }
        return true;
    }
};