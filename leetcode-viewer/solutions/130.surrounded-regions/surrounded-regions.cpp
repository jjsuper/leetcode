class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=m? board[0].size(): 0;
        
        
        for(int i=0; i<m; ++i) {
            check(board, i, 0);
            if(n>1) check(board, i, n-1);
        }
        
        for(int i=0; i<n; ++i) {
            check(board, 0, i);
            if(m>1) check(board, m-1, i);
        } 
        
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j) {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='1') board[i][j]='O';
            }
        
        
        
    }
private:
    void check(vector<vector<char>>& board, int row, int col) {
        int m=board.size(), n=m? board[0].size(): 0;
        if(board[row][col]=='O') {
            board[row][col]='1';
            if(row>1) check(board, row-1, col);
            if(col>1) check(board, row, col-1);
            if(row<m-2) check(board, row+1, col);
            if(col<n-2) check(board, row, col+1);
        }
    }
};