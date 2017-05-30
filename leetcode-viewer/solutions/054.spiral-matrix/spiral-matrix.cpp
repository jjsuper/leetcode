class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        
        if(matrix.empty()) return ret;
        
        int beginRow=0, beginCol=0, endRow=matrix.size()-1, endCol=matrix[0].size()-1;
        
        
        while(beginRow<=endRow && beginCol<=endCol)
        {
            for(int i=beginCol; i<=endCol; ++i)
            {
                ret.push_back(matrix[beginRow][i]);
            }
            beginRow++;
            
            for(int i=beginRow; i<=endRow; ++i)
            {
                ret.push_back(matrix[i][endCol]);
            }
            endCol--;
            
            if(beginRow<=endRow)
            {
                for(int i=endCol; i>=beginCol; --i)
                {
                    ret.push_back(matrix[endRow][i]);   
                }
                endRow--;
            }
            
            if(beginCol<=endCol)
            {
                for(int i=endRow; i>=beginRow; --i)
                {
                    ret.push_back(matrix[i][beginCol]);
                }
                beginCol++;
            }
        }
        
        
        return ret;
        
        
    }
};