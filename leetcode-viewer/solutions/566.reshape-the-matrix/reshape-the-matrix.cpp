class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> res(r, vector<int>(c, 0));
        int m=nums.size();
        int n=m?nums[0].size(): 0;
        
        if(m*n!=r*c) return nums;
        
        
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                int tmp = i*c + j;
                int x=tmp/n, y=tmp%n;
                res[i][j]=nums[x][y];
            }
        }
        
        
        return res;
    }
};