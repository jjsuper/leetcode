class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum=0;
        int mindist=INT_MAX;
        
        for(int i=0; i<nuts.size(); ++i) {
            int x=nuts[i][0], y=nuts[i][1];
            int treenut=abs(x-tree[0])+abs(y-tree[1]);
            int dist=abs(x-squirrel[0])+abs(y-squirrel[1])-treenut;
            sum+=treenut*2;
            mindist=min(mindist, dist);
        }
        
        return sum+mindist;
    }
};