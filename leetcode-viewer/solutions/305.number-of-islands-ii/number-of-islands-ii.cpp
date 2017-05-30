class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> root(m*n, -1);
        vector<int> res;
        vector<pair<int, int>> dirs={{1,0}, {-1,0}, {0,1}, {0,-1}};
        int island=0;
        
        
        for(auto pos: positions) {
            int x=pos.first, y=pos.second, idx=x*n+y;
            island++;
            root[idx]=idx;
            for(auto dir: dirs) {
                int xd=x+dir.first, yd=y+dir.second, idxd=xd*n+yd;
                if(xd>-1 && xd<m && yd>-1 && yd<n && root[idxd]!=-1) {
                    int rootPos=findroot(idx, root), rootDir=findroot(idxd, root);
                    if(rootPos!=rootDir) {
                        root[rootPos]=rootDir;
                        island--;
                    }
                }
            }
            res.push_back(island);
        }
        
        return res;
    }
private:
    int findroot(int idx, vector<int>& root) {
        while(root[idx]!=idx) {
            root[idx]=root[root[idx]];
            idx=root[idx];
        }
        return idx;
    }
};