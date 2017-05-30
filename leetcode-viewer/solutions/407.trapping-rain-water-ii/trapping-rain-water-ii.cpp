class Solution {
    
    
class cell {
public:
    int row;
    int col;
    int height;
    cell(int row, int col, int height) {
        this->row=row;
        this->col=col;
        this->height=height;
    }
};
class mycomp {
public:
    bool operator()(const cell& a, const cell&b) const {
        return a.height>b.height;
    }    
};
    
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) return 0;
        priority_queue<cell, vector<cell>, mycomp> queue;        

        int m=heightMap.size(), n=heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        for(int i=0; i<m; ++i) {
            visited[i][0]=1;
            visited[i][n-1]=1;
            queue.push(cell(i,0,heightMap[i][0]));
            queue.push(cell(i,n-1,heightMap[i][n-1]));
        }
        for(int i=0; i<n; ++i) {
            visited[0][i]=1;
            visited[m-1][i]=1;
            queue.push(cell(0,i,heightMap[0][i]));
            queue.push(cell(m-1,i,heightMap[m-1][i]));
        }        
        
        int res=0;
        vector<pair<int, int>> dirs={{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while(!queue.empty()) {
            cell cur=queue.top();
            queue.pop();
            for(auto dir: dirs) {
                int row=cur.row+dir.first;
                int col=cur.col+dir.second;
                if(row>-1 && row<m && col>-1 && col<n && !visited[row][col]) {
                    visited[row][col]=1;
                    res+=max(0, cur.height-heightMap[row][col]);    
                    queue.push(cell(row, col, max(cur.height, heightMap[row][col])));
                }
            }
        }
        
        
        
        
        return res;
    }
};