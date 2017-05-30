class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        vector<vector<int>> t(2, vector<int>(3, 0));
        
        for(int i=0; i<costs.size(); ++i) {
            t[1][0]=costs[i][0]+min(t[0][1],t[0][2]);
            t[1][1]=costs[i][1]+min(t[0][0],t[0][2]);
            t[1][2]=costs[i][2]+min(t[0][0],t[0][1]);
            
            t[0]=t[1];
        }
        
        return min(t[0][0], min(t[0][1], t[0][2]));
    }
};