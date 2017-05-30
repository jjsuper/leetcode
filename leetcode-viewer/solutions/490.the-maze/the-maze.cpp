class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        stack<pair<int, int>> stops;
        //vector<pair<int, int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(),0));
        
        stops.push(make_pair(start[0],start[1]));
        visited[start[0]][start[1]]=1;
        
        while(!stops.empty()) {
            //int x=stops.top().first, y=stops.top().second;
            stack<pair<int, int>> reach;
            reach=getreach(maze, stops.top(), visited);
            stops.pop();
            
            while(!reach.empty()) {
                int i=reach.top().first, j=reach.top().second;
                cout << i << j << endl;
                if(i==destination[0]&&j==destination[1]) return true;
                //if(visited[i][j]==0) {
                    visited[i][j]=1;
                    stops.push(reach.top());
                //}
                reach.pop();
            }
            
            
        }
        
        
        
        return false;
    }
    
    stack<pair<int, int>> getreach(vector<vector<int>>& maze, pair<int, int>& start, vector<vector<bool>>& visited) {
        stack<pair<int, int>> res;
        //
        int x=start.first, y=start.second;
        while(x<maze.size()-1 && !maze[x+1][y]) x++;
        if(visited[x][y]==0) { res.push(make_pair(x,y)); cout << x << y << "x++" << endl;}
        //
        x=start.first; y=start.second;
        while(x>0 && !maze[x-1][y]) x--;
        if(visited[x][y]==0) {res.push(make_pair(x,y)); cout << x << y << "x--" << endl;}
        //
        x=start.first; y=start.second;
        while(y<maze[0].size()-1 && !maze[x][y+1]) y++;
        if(visited[x][y]==0) {res.push(make_pair(x,y)); cout << x << y << "y++" << endl;}
        //
        x=start.first; y=start.second;
        while(y>0 && !maze[x][y-1])  y--;
        if(visited[x][y]==0) {res.push(make_pair(x,y));   cout << x << y << "y--" << endl;}   
        
        return res;
    }
    
};