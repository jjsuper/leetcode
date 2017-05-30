class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int m=matrix.size(), n=matrix[0].size();
        /*
        for(int i=0; i<m+n-1; ++i) {
            if(i%2==0) {
                for(int j=max(i,m-1); j>max(-1,i-n); --j) {
                    int k=i-j;
                    res.push_back(matrix[j][k]);
                }
            } 
            else {
                for(int j=max(0,i-n+1); j<min(m-1,i+1); ++j) {
                    int k=i-j;
                    res.push_back(matrix[j][k]);
                }
            }
        }*/
        
        vector<vector<int>> tmp(m+n-1);
        for(int i=0; i<m+n-1; ++i) {
            int row=max(0, i-n+1);
            int col=min(i, n-1);
            for( ; row<m && col>-1; row++, col--) {
                tmp[i].push_back(matrix[row][col]);
            }
        }
        
        for(int i=0; i<tmp.size(); ++i) {
            if(i%2) res.insert(res.end(), tmp[i].begin(), tmp[i].end());
            else res.insert(res.end(), tmp[i].rbegin(), tmp[i].rend());
        }
    
        return res;
    }
};