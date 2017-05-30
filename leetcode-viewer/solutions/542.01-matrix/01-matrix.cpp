class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=m? matrix[0].size(): 0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(matrix[i][j]==0)
                    q.push(make_pair(i,j));
                else
                    matrix[i][j]=20000;
            }
        }
        
        vector<pair<int, int>> dir={{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while(!q.empty()) {
            pair<int, int> cur=q.front();
            q.pop();
            
            for(int i=0; i<4; ++i) {
                int x=cur.first+dir[i].first;
                int y=cur.second+dir[i].second;
                if(x<0 || x>=m || y<0 || y>=n || matrix[x][y]<= matrix[cur.first][cur.second]+1) continue;
                matrix[x][y]=matrix[cur.first][cur.second]+1;
                q.push(make_pair(x,y));
            }
        }
        
        
        
        return matrix;
    }
};