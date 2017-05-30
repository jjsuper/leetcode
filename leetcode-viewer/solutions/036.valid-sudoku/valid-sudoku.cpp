class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool row[9][9]={false};
        bool col[9][9]={false};
        bool box[9][9]={false};
        
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(board[i][j]=='.') continue;
                
                int tmp=board[i][j]-'1';
                if(row[i][tmp]) return false;
                if(col[j][tmp]) return false;
                if(box[(i/3)*3+j/3][tmp]) return false;
                
                row[i][tmp]=true;
                col[j][tmp]=true;
                box[(i/3)*3+j/3][tmp]=true;
                
                
                
            }
            
            
            
            
        }
        
        return true;
        
        
    }
};