class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int dist=INT_MAX;
        string res="";
        return findShortestWay(maze, ball, hole, vector<int>{0, 0}, 0, "", dist, res);
    }
private:
    string findShortestWay(vector<vector<int>>& maze, vector<int> ball, vector<int>& hole, vector<int> dir, int step, string path, int& dist, string& res) {
        if(step < dist) {
            if(dir[0]||dir[1]) {
                while(ball[0]+dir[0]>-1 && ball[0]+dir[0]<maze.size() && ball[1]+dir[1]>-1 && ball[1]+dir[1]<maze[0].size() && maze[ball[0]+dir[0]][ball[1]+dir[1]]!=1 ) {
                    ball[0]+=dir[0];
                    ball[1]+=dir[1];
                    step++;
                    if(ball[0]==hole[0] && ball[1]==hole[1] && step<dist) {
                        dist=step;
                        res=path;
                    }
                }
            }
            if(maze[ball[0]][ball[1]]==0 || step+2<maze[ball[0]][ball[1]]) {
                maze[ball[0]][ball[1]]=step+2;
                if(dir[0]==0) findShortestWay(maze, ball, hole, vector<int>{1,0}, step, path+"d", dist, res);
                if(dir[1]==0) findShortestWay(maze, ball, hole, vector<int>{0,-1}, step, path+"l", dist, res);
                if(dir[1]==0) findShortestWay(maze, ball, hole, vector<int>{0,1}, step, path+"r", dist, res);
                if(dir[0]==0) findShortestWay(maze, ball, hole, vector<int>{-1,0}, step, path+"u", dist, res);
            }
        }
        return dist==INT_MAX? "impossible": res;
    }
    
    
    
};