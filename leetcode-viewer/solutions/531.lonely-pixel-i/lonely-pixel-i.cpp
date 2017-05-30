class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if(picture.empty() || picture[0].empty()) return 0;
        int m=picture.size();
        int n=picture[0].size();
        
        int res=0;
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j) 
                if(picture[i][j]=='B') {
                    row[i]++;
                    col[j]++;
                }
        
        for(int i=0; i<m; ++i) 
            for(int j=0; j<n && row[i]==1; ++j) 
                if(col[j]==1 && picture[i][j]=='B')
                    res++;
        
        
        return res;
    }
};