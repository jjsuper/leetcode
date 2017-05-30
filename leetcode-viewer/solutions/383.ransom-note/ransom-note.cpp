class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26,0);
        for(auto c: ransomNote) count[c-'a']--;
        for(auto c: magazine)   count[c-'a']++;
        for(auto num: count)    if(num<0) return false;
        return true;
    }
};