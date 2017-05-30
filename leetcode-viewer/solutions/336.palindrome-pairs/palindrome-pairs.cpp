class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
   /*     
Steps:

Traverse the array, build map. Key is the reversed string, value is index in array (0 based)

Edge case - check if empty string exists. It's interesting that for given words {"a", ""}, it's expected to return two results [0,1] and [1,0]. Since my main logic can cover [0, 1] concatenate("a", ""), so as to cover the other situation concatenate("", "a"), I need to traverse the words array again, find the palindrome word candidate except "" itself, and add pair("", palindrome word) to the final answer.

Main logic part. Partition the word into left and right, and see 1) if there exists a candidate in map equals the left side of current word, and right side of current word is palindrome, so concatenate(current word, candidate) forms a pair: left | right | candidate. 2) same for checking the right side of current word: candidate | left | right.
     */
        unordered_map<string, int> hash;
        vector<vector<int>> res;
        
        for(int i=0; i<words.size(); ++i) {
            string key=words[i];
            reverse(key.begin(), key.end());
            hash[key]=i;
        }
        
        if(hash.find("")!=hash.end()) {
            for(int i=0; i<words.size(); ++i) {
                if(words[i]!="" && isPalindrome(words[i])) {
                    res.push_back({hash[""], i});
                    //res.push_back({i, hash[""]});
                }
            }
        }
     
        for(int i=0; i<words.size(); ++i) {
            for(int j=0; j<words[i].size(); ++j) {
                string left=words[i].substr(0, j);
                string right=words[i].substr(j);
                if(hash.count(left) && isPalindrome(right) && hash[left]!=i) res.push_back({i, hash[left]});
                if(hash.count(right) && isPalindrome(left) && hash[right]!=i) res.push_back({hash[right], i});
            }    
        }
        
        return res;
    }
private:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;  
        } 
        
        return true;
    }
};