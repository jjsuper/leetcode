class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0)); 
        
        int num=1;
        
        int beginRow=0, beginCol=0, endRow=n-1, endCol=n-1;
        
        while(beginRow<=endRow&&beginCol<=endCol)
        {
            for(int i=beginCol; i<=endCol; ++i)
                matrix[beginRow][i]=num++;
            beginRow++;
            
            for(int i=beginRow; i<=endRow; ++i)
                matrix[i][endCol]=num++;
            endCol--;
            
            for(int i=endCol; i>=beginCol; --i)
                matrix[endRow][i]=num++;
            endRow--;
            
            for(int i=endRow; i>=beginRow; --i)
                matrix[i][beginCol]=num++;
            beginCol++;
            
        }
        
        
        
        
        
        return matrix;
    }
};