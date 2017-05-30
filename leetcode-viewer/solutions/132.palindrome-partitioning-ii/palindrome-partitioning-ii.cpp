class Solution {
public:
/*
    int minCut(string s) {
        if(s.empty()) return 0;
        return helper(s, 0, -1);
    }    
        
private:
    int helper(string s, int index, int num) {
        if(index==s.size()) {
            return num;    
        }
        
        for(int i=index; i<s.size(); ++i) 
            if(isPalindrome(s.substr(index, i-index+1))) 
                if(num==-1) num=helper(s, i+1, num+1);
                else num=min(num, helper(s, i+1, num+1));
        
        return num;
    }
    
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        for(int i=0; i<s.size()/2; ++i) {
            if(s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }    */
    
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
    
};