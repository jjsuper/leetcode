class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<bool> visited(n, false);
        int groups=0;
        for (int i = 0; i < n; ++i) {
            groups += dfs(i, M, visited) > 0;
        }
        return groups;
    }
private:
    int dfs(int i, vector<vector<int>>& M, vector<bool>& visited) {
        if(visited[i] == true) return 0;
        visited[i] = true;
        int p = 1;
        for (int j = 0; j < M.size(); ++j) {
            if (i != j && M[i][j] == 1) 
                p += dfs(j, M, visited);
        }
        return p;
    }
};