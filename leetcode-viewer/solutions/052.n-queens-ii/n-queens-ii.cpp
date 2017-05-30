class Solution {
public:
    int totalNQueens(int n) {
        fcol.assign(n, 1);
        fdiagonal.assign(2*n-1, 1);
        fantidiagonal.assign(2*n-1, 1);
        int count=0;
        solveNQueens(count, 0, n);
        return count;
    }
private:
    vector<bool> fcol;
    vector<bool> fdiagonal;
    vector<bool> fantidiagonal;
    
    void solveNQueens(int& count, int row, int n) {
        if(row==n) {
            count++;
            return;
        }
        
        for(int col=0; col<n; ++col) {
            if(fcol[col] && fdiagonal[col-row+n-1] && fantidiagonal[row+col]) {
                fcol[col]=fdiagonal[col-row+n-1]=fantidiagonal[row+col]=0;
                solveNQueens(count, row+1, n);
                fcol[col]=fdiagonal[col-row+n-1]=fantidiagonal[row+col]=1;
            }
        }
    }
};