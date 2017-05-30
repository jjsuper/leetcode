class Trie {
class TrieNode {
public:
    TrieNode* next[26];    
    bool is_end=false;
};

public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p=root;
        for(int i=0; i<word.size(); ++i) {
            if(p->next[word[i]-'a']==NULL) {
                p->next[word[i]-'a']=new TrieNode();
            }
            p=p->next[word[i]-'a'];
        }
        p->is_end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(int i=0; i<word.size() && p!=NULL; ++i)
            p=p->next[word[i]-'a'];
        return p!=NULL && p->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(int i=0; i<prefix.size() && p!=NULL; ++i)
            p=p->next[prefix[i]-'a'];
        return p!=NULL;
    }
private:
    TrieNode* root;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */