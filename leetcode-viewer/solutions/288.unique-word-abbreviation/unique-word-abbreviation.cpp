class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(string word: dictionary) {
            string key=getkey(word);
            if(hash.count(key)) {
                if(hash[key]!=word) {
                    hash[key]="";
                }
            }
            else { 
                hash[key]=word;
            }
        }
    }
    
    bool isUnique(string word) {
        return !hash.count(getkey(word)) || hash[getkey(word)]==word;
    }
private:
    unordered_map<string, string> hash;
    string getkey(string word) {
        return word.size()>2? word[0]+to_string(word.size()-2)+word[word.size()-1] : word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */