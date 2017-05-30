class WordDictionary {
    
class TrieNode {
public:
    TrieNode* next[26];
    bool is_end=false;
};
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p=root;
        for(int i=0; i<word.size(); ++i) {
            if(p->next[word[i]-'a']==NULL) {
                p->next[word[i]-'a']=new TrieNode();
            }
            p=p->next[word[i]-'a'];
        }
        p->is_end=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root);
    }
private:
    TrieNode* root;
    
    bool search(string word, TrieNode* root) {
        TrieNode* p=root;
        for(int i=0; i<word.size() && p!=NULL; ++i) {
            if(word[i]=='.') {
                for(int j=0; j<26; ++j) {
                    if(search(word.substr(i+1), p->next[j])) return true;
                }
                p=p->next[0];
            }
            else {
                p=p->next[word[i]-'a'];
            }
        }
        return p!=NULL && p->is_end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */