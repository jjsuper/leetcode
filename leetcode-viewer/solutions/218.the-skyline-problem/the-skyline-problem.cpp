class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        pair<int, int> cur({0, 0});
        vector<pair<int, int>> res;
        multiset<pair<int, int>> seq;
        
        for(auto b: buildings) {
            seq.insert(make_pair(b[0], -b[2]));
            seq.insert(make_pair(b[1], b[2]));
        }
        
        multiset<int> height={0};
        
        for(auto s: seq) {
            if(s.second<0) height.insert(-s.second);
            else height.erase(height.find(s.second));
            if(*height.rbegin()!=cur.second) {
                cur.first=s.first;
                cur.second=*height.rbegin();
                res.push_back(cur);
            }
        }
        
        return res;
    }
};