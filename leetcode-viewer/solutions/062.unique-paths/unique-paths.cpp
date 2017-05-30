class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
        if(m==1) return 1;
        if(n==1) return 1;
        return uniquePaths(m-1,n) + uniquePaths(m,n-1);
        */
        
        int num[m][n];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0) num[i][j]=1;
                else num[i][j]=num[i-1][j]+num[i][j-1];
            }
        }
        
        return num[m-1][n-1];
        
        
    }
};