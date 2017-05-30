class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=m? grid[0].size(): 0;
        if(m==0 || n==0) return -1;
        
        int mindist=-1, walk=0;
        vector<vector<int>> total(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs={{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j]==1) {
                    mindist=-1;
                    queue<pair<int, int>> que;
                    que.emplace(i,j);
                    vector<vector<int>> dist(m, vector<int>(n, 0));
                    while(!que.empty()) {
                        auto it=que.front();
                        int x=it.first, y=it.second;
                        que.pop();
                        for(auto dir: dirs) {
                            int p=x+dir.first;
                            int q=y+dir.second;
                            if(p>-1 && p<m && q>-1 && q<n && grid[p][q]==walk) {
                                que.emplace(p,q);
                                grid[p][q]--;
                                dist[p][q]=dist[x][y]+1;
                                total[p][q]+=dist[p][q];
                                if(mindist<0 || mindist>total[p][q])
                                    mindist=total[p][q];
                            }
                        }
                    }
                    walk--;
                }    
            }
        }
        
        return mindist;
    }
};