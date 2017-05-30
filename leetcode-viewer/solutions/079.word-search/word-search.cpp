class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.empty()) return false;
        vector<vector<bool>> use(board.size(), vector<bool>(board[0].size(), 0));
        
        for(int i=0; i<board.size(); ++i) 
            for(int j=0; j<board[0].size(); ++j)
                if(helper(board, word, use, i, j))
                    return true;
        return false;
    }
    
private:
    bool helper(vector<vector<char>>& b, string w, vector<vector<bool>>& use, int i, int j) {
        if(w.empty()) return true;
        
        if(b[i][j]==w[0] && use[i][j]==0) {
            use[i][j]=1;
            
            if(w.size()==1) return true;
            
            if(i<b.size()-1 && helper(b, w.substr(1), use, i+1, j)) return true;
            if(i>0 && helper(b, w.substr(1), use, i-1, j)) return true;
            if(j<b[0].size()-1 && helper(b, w.substr(1), use, i, j+1)) return true;
            if(j>0 && helper(b, w.substr(1), use, i, j-1)) return true;

            use[i][j]=0;
        }
        
        return false;
    }
    
    
};