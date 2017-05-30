class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if(picture.empty() || picture[0].empty()) return 0;
        
        int m=picture.size(), n=picture[0].size();
        int res=0;
        
        unordered_map<int, unordered_set<int>> row;
        unordered_map<int, unordered_set<int>> col;
        
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j) 
                if(picture[i][j]=='B') {
                    row[i].insert(j);
                    col[j].insert(i);
                }
        
        for(int i=0; i<m; ++i)
            for(int j=0; j<n && row[i].size() == N; ++j) 
                if(picture[i][j]=='B' && col[j].size()==N) {
                   bool lonely=true;
                   for(int k: col[j]) {
                       if(row[k]!=row[i]) {
                           lonely=false;
                           break;
                       }
                   } 
                   res+=lonely;
                }        
        
        return res;
    }
};