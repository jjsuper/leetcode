class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        m=matrix.size();
        n=m>0? matrix[0].size(): 0;
        num=vector<vector<int>>(m, vector<int>(n, 0));
        BIT=vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j)
                update(i, j, matrix[i][j]);
        }
    }
    
    void update(int row, int col, int val) {
        int diff=val-num[row][col];
        num[row][col]=val;
        for(int i=row+1; i<=m; i+=(i&-i)) {
            for(int j=col+1; j<=n; j+=(j&-j)) {
                BIT[i][j]+=diff;    
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2+1, col2+1)-getSum(row2+1, col1)-getSum(row1, col2+1)+getSum(row1, col1);
    }
    
    int getSum(int row, int col) {
        int sum=0;
        for(int i=row; i>0; i-=(i&-i)) {
            for(int j=col; j>0; j-=(j&-j)) {
                sum+=BIT[i][j];
            }   
        }
        return sum;
    }
    
private:
    vector<vector<int>> BIT;
    vector<vector<int>> num;
    int m;
    int n;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */