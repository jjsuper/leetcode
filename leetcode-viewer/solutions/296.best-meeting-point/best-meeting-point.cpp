class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) { //median
        int m=grid.size();
        int n=m? grid[0].size(): -1;
        int total=0;
        vector<int> num;
        
        for(int i=0; i<m; ++i) 
            for(int j=0; j<n; ++j)
                if(grid[i][j]==1) {
                    num.push_back(i);
                }        
        for(int i=0; i<num.size()/2; ++i) {
            total += num[num.size()-1-i]-num[i];
        }
        
        num.clear();
        
        for(int i=0; i<n; ++i) 
            for(int j=0; j<m; ++j)
                if(grid[j][i]==1) {
                    num.push_back(i);
                }        
        for(int i=0; i<num.size()/2; ++i) {
            total += num[num.size()-1-i]-num[i];
        }        
        
        return total;
    }
};