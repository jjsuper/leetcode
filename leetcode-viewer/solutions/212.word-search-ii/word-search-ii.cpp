class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(words.empty() || board.empty() || board[0].empty()) return res;
        
        buildTrie(words);
        
        for(int i=0; i<board.size(); ++i) {
            for(int j=0; j<board[0].size(); ++j) {
                dfs(board, i, j, root, res, words);
            }
        }
        
        return res;
    }
    
    
private:
    class Trie{
        public:
            Trie* next[26];
            bool is_leaf;
            int idx;
            Trie() {
                is_leaf=false;
                idx=0;
                for(int i=0; i<26; ++i) next[i]=NULL;
            }
            ~Trie() {
                for(int i=0; i<26; ++i) delete next[i];
            }
    };

    Trie* root;
 
    void buildTrie(vector<string>& words) {
        root=new Trie();
        for(int i=0; i<words.size(); ++i) {
            Trie* p=root;
            for(int j=0; j<words[i].size(); ++j) {
                if(p->next[words[i][j]-'a']==NULL)
                    p->next[words[i][j]-'a']=new Trie();
                p=p->next[words[i][j]-'a'];
            }
            p->is_leaf=true;
            p->idx=i;
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, Trie* root, vector<string>& res, vector<string>& words) {
        char tmp=board[i][j];
        if(tmp=='X') return;
        if(root->next[tmp-'a']==NULL) return;
        
        if(root->next[tmp-'a']->is_leaf) {
            root->next[tmp-'a']->is_leaf=false;
            res.push_back(words[root->next[tmp-'a']->idx]);
        }
        board[i][j]='X';    
        
        if(i>0) dfs(board, i-1, j, root->next[tmp-'a'], res, words);
        if(j>0) dfs(board, i, j-1, root->next[tmp-'a'], res, words);  
        if(i<board.size()-1) dfs(board, i+1, j, root->next[tmp-'a'], res, words);
        if(j<board[0].size()-1) dfs(board, i, j+1, root->next[tmp-'a'], res, words); 
    
        board[i][j]=tmp;
    }




};