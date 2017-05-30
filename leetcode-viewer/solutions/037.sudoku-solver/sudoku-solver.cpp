class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, 1));
        vector<vector<bool>> col(9, vector<bool>(9, 1));
        vector<vector<bool>> box(9, vector<bool>(9, 1));
        
        
        cout << "right" << endl;
        for(int i=0; i<9; ++i)
            for(int j=0; j<9; ++j) 
                if(board[i][j]!='.') {
                    row[i][board[i][j]-'1']=0;
                    col[j][board[i][j]-'1']=0;
                    box[i/3*3+j/3][board[i][j]-'1']=0;
            }
        
        
        cout << "2r" << endl;
        solveSudoku(board, row, col, box, 0, 0);
        
    }
private:
    bool solveSudoku(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& box, int i, int j) {
        cout << "in" << endl;
        if(i==9) return true;
        if(j==9) return solveSudoku(board, row, col, box, i+1, 0);
        if(board[i][j]!='.') return solveSudoku(board, row, col, box, i, j+1);
        
        for(int k=0; k<9; ++k) {
            if(row[i][k] && col[j][k] && box[i/3*3+j/3][k]) {
                row[i][k]=col[j][k]=box[i/3*3+j/3][k]=0;
                board[i][j]=k+'1';
                if(solveSudoku(board, row, col, box, i, j+1)) return true;
                board[i][j]='.';
                row[i][k]=col[j][k]=box[i/3*3+j/3][k]=1;
            }
        }
        return false;
    }
};