class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minlen(triangle.back());
        
        
        for(int i=triangle.size()-2; i>=0; i--)
        {
            for(int j=0; j<triangle[i].size(); ++j)
            {
                minlen[j]=min(minlen[j], minlen[j+1])+triangle[i][j];
            }
            
        }
        
        
        
        return minlen[0];
    }
};