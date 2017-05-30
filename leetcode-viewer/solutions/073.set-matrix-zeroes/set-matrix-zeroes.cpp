class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int col=0, row=0;
        
        for(int i=0; i<m; ++i)
        {
            if(!matrix[i][0]) col=1;
        }
        
        for(int i=0; i<n; ++i)
        {
            if(!matrix[0][i]) row=1;
        }
        
        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
            {
                if(!matrix[i][j]) matrix[0][j]=matrix[i][0]=0;
            }
        

        
        
        
        
        
        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
            {
                if(!matrix[i][0]||!matrix[0][j]) matrix[i][j]=0;
            }
        
        for(int i=0; i<m && col; ++i)   matrix[i][0]=0;
        for(int i=0; i<n && row; ++i)   matrix[0][i]=0;
        
        
    }
};