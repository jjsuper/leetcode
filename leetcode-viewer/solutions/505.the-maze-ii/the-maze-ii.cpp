class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m=maze.size();
        int n=m? maze[0].size(): 0;
        
        vector<vector<int>> dists(m, vector<int>(n, -1));
        vector<vector<int>> dir={{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<vector<int>> q;
        
        q.push(start);
        dists[start[0]][start[1]]=0;
        
        while(!q.empty()) {
            int x=q.front()[0], y=q.front()[1];
            int dist=dists[x][y];
            q.pop();
            
            //cout << x << " " << y << endl;
            
            for(int k=0; k<4; ++k) {
                int i=x, j=y;
                int step=0;
                int d_i=dir[k][0], d_j=dir[k][1];
                //cout << "i=" << i << "j=" << j << endl;
                
                while(d_i+i>-1 && d_i+i<m && d_j+j>-1 && d_j+j<n && maze[d_i+i][d_j+j]==0) {
                    step++;
                    i+=d_i;
                    j+=d_j;
                }
                // cout << "queue" << x << " " << y << endl;
                if(dists[i][j]==-1) {
                    dists[i][j]=dist+step;
                    q.push(vector<int>{i, j});
                }
                else if(dists[i][j]>dist+step) {
                    dists[i][j]=dist+step;
                    q.push(vector<int>{i, j});
                }
            }
        }
 
        return dists[destination[0]][destination[1]];
    }
};