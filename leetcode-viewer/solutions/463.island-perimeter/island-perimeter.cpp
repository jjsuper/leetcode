class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total=0;
        
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[0].size(); ++j) {
                if(grid[i][j]==1) {
                    int cnt=4;
                    if(i>0&&grid[i-1][j]==1) cnt--;
                    if(i+1<grid.size()&&grid[i+1][j]==1) cnt--;
                    if(j>0&&grid[i][j-1]==1) cnt--;
                    if(j+1<grid[0].size()&&grid[i][j+1]==1) cnt--;
                    total+=cnt;
                }
            }
        
        return total;
    }
};