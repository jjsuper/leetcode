class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row=0;
        vector<int> col(grid[0].size(), 0);
        int result=0;
        
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[0].size(); ++j) {
                if(!j || grid[i][j-1]=='W') {
                    row=0;
                    for(int k=j; k<grid[0].size() && grid[i][k]!='W'; ++k) {
                        row += grid[i][k]=='E';
                    }
                }
                if(!i || grid[i-1][j]=='W') {
                    col[j]=0;
                    for(int k=i; k<grid.size() && grid[k][j]!='W'; ++k) {
                        col[j] += grid[k][j]=='E';
                    }
                }
                if(grid[i][j]=='0')
                    result = max(result, row+col[j]);
            }
        return result;
    }
};