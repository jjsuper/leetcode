class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        cout << n << ' ' << m << endl;
        
        vector<vector<int>> minSum(n, vector<int>(m, 0));
        
        minSum[0][0]=grid[0][0];
        
        
        cout << "minSum[0][0]=" << minSum[0][0] << endl;
        
        for(int i=1; i<m; ++i)
        {
            minSum[0][i]=minSum[0][i-1]+grid[0][i];
            cout << "minSum[0][" << i << "]=" << minSum[0][i] << endl;
        }
            
        for(int i=1; i<n; ++i)
        {
            minSum[i][0]=minSum[i-1][0]+grid[i][0];
            cout << "minSum[" << i << "][0]=" << minSum[i][0] << endl;
        }
        
        
        for(int i=1; i<n; ++i)
            for(int j=1; j<m; ++j)
            {
                minSum[i][j]=min(minSum[i-1][j], minSum[i][j-1]) + grid[i][j];
                
            }
        
        
        
        return minSum[n-1][m-1];
    }
};