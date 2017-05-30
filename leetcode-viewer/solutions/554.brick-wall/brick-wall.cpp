class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hash;
        int min_bricks=wall.size();
        
        for(auto it: wall) {
            for(int i=0, width=0; i<it.size()-1; ++i) {
                width+=it[i];
                hash[width]++;
                min_bricks=min(min_bricks, (int)wall.size()-hash[width]);
            }
        }
        
        return min_bricks;
    }
};