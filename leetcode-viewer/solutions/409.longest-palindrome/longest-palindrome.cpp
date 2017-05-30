class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(52,0);
        int total = 0;
        bool odd=0;
        
        for(auto c: s) {
            if(c-'a'<0) count[c-'A'+26]++;
            else count[c-'a']++;
        }
        for(auto num: count) {
            if(num%2==1) { total+=num-1; odd=true;}
            else total+=num;
        }
        return odd?total+1:total;
    }
};