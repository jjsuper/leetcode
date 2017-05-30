class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int begin=0, end=m*n-1;
        
        while(begin<=end)
        {
            int mid=(begin+end)/2;
            int x=mid%n; 
            int y=mid/n;
            
            if(matrix[y][x]==target) return true;
            if(matrix[y][x]>target) end=mid-1;
            else begin=mid+1;
            
        }
        
        
        return false;
    }
};