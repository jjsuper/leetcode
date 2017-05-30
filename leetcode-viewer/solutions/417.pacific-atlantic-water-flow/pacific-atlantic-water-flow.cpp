class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if(matrix.empty()) return res;
        
        queue<pair<int, int>> pacQue;
        queue<pair<int, int>> atlQue;
        vector<vector<bool>> pacReach;
        vector<vector<bool>> atlReach;
        
        for(int i=0; i<matrix.size(); ++i) pacQue.push(pair<int, int>(i,0));
        for(int i=0; i<matrix[0].size(); ++i) pacQue.push(pair<int, int>(0,i));
        
        for(int i=0; i<matrix.size(); ++i) atlQue.push(pair<int, int>(i,matrix[0].size()-1));
        for(int i=0; i<matrix[0].size(); ++i) atlQue.push(pair<int, int>(matrix.size()-1, i));   
        
        pacReach=reach(pacQue, matrix);
        atlReach=reach(atlQue, matrix);
        
        //print(pacReach);
        //print(atlReach);
        
        for(int i=0; i<matrix.size(); ++i) {
            for(int j=0; j<matrix[0].size(); ++j)
                if(pacReach[i][j] && atlReach[i][j]) res.push_back(pair<int, int>(i,j));
        }
        
        return res;
    }
private:
    vector<vector<bool>> reach(queue<pair<int, int>>& source, vector<vector<int>>& matrix) {
        vector<vector<bool>> res(matrix.size(), vector<bool>(matrix[0].size(), 0));
        
        vector<pair<int, int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!source.empty()) {
            int x=source.front().first;
            int y=source.front().second;
            source.pop();
            res[x][y]=1;
            for(auto d:dir) {
                int p=x+d.first;
                int q=y+d.second;
                if(p<0 || p>=matrix.size()) continue;
                if(q<0 || q>=matrix[0].size()) continue;
                if(res[p][q]) continue;
                if(matrix[p][q]>=matrix[x][y]) {
                    res[p][q]=1;
                    source.push(pair<int, int>(p,q));
                }
            }
        }
        
        return res;
    }
    void print(vector<vector<bool>>& matrix) {
        for(auto i:matrix) {
            for(auto j:i) {
                cout << (j?"1 ":"0 ");
            }
            cout << endl;
        }
        cout << endl;
    }
};