class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> gates;
        vector<pair<int, int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i=0; i<rooms.size(); ++i)
            for(int j=0; j<rooms[0].size(); ++j)
                if(!rooms[i][j]) gates.push(make_pair(i,j));
        
        while(!gates.empty()) {
            int i=gates.front().first, j=gates.front().second;
            gates.pop();
            for(auto d:dir) {
                int ni=i+d.first, nj=j+d.second;
                if(ni>-1 && nj>-1 && ni<rooms.size() && nj<rooms[0].size() && rooms[ni][nj]>0 && rooms[ni][nj]>rooms[i][j]+1) {
                    rooms[ni][nj]=rooms[i][j]+1;
                    gates.push(make_pair(ni,nj));
                }
            }
            
        }
        
        
    }
};