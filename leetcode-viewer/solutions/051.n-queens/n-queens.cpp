class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n, string(n, '.'));
        fcol.assign(n, 1);
        fdiagonal.assign(2*n-1, 1);
        fantidiagonal.assign(2*n-1, 1);
        solveNQueens(res, nQueens, 0, n);
        return res;
    }
private:
    vector<bool> fcol;
    vector<bool> fdiagonal;
    vector<bool> fantidiagonal;
    
    void solveNQueens(vector<vector<string>>& res, vector<string>& nQueens, int row, int n) {
        if(row==n) {
            res.push_back(nQueens);
            return;
        }
        
        for(int col=0; col<n; ++col) {
            if(fcol[col] && fdiagonal[col-row+n-1] && fantidiagonal[row+col]) {
                fcol[col]=fdiagonal[col-row+n-1]=fantidiagonal[row+col]=0;
                nQueens[row][col]='Q';
                solveNQueens(res, nQueens, row+1, n);
                nQueens[row][col]='.';
                fcol[col]=fdiagonal[col-row+n-1]=fantidiagonal[row+col]=1;
            }
        }
    }
    
    
    
};