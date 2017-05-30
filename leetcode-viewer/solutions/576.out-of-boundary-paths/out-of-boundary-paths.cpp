class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        /*queue<pair<int, int>> q;
        //vector<pair<int, int>> dirs={{1,0}, {-1,0}, {0,1}, {0,-1}};
        int cnt=0;
        
        q.push(make_pair(i,j));
        while(!q.empty() && N) {
            N--;
            int size=q.size();
            for(int k=0; k<size; ++k) {
                int x=q.front().first, y=q.front().second;
                q.pop();
                
                if(N) {
                    if(x>0) q.push(make_pair(x-1, y));
                    if(x+1<m) q.push(make_pair(x+1, y));
                    if(y>0) q.push(make_pair(x, y-1));
                    if(y+1<n) q.push(make_pair(x, y+1));
                }
                
                cnt += (x==0) + (x==m-1) + (y==0) + (y==n-1);
                cnt = cnt % 1000000007;
            }
            
        }
        
        */
        
        int MOD=1000000007;
        
        vector<vector<int>> cur(m, vector<int>(n, 0));
        int dirs[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
        cur[i][j]=1;
        int cnt=0;
        
        for(int k=0; k<N; ++k) {
            vector<vector<int>> next(m, vector<int>(n, 0));
            for(int r=0; r<m; ++r) {
                for(int c=0; c<n; ++c) {
                    for(auto dir : dirs) {
                        int nr=r+dir[0];
                        int nc=c+dir[1];
                        if(nr<0 || nr>=m || nc<0 || nc>=n) {
                            cnt = (cnt+cur[r][c]) % MOD;
                        }
                        else {
                            next[nr][nc] = (next[nr][nc] + cur[r][c]) % MOD;
                        }
                    }
                }
            }
            cur=next;
        }
        

        return cnt;
    }
};