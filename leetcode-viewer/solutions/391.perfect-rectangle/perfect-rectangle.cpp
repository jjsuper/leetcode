class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.empty()||rectangles[0].empty()) return false;
        
        set<pair<int, int>> hash;
        int x1=INT_MAX, x2=INT_MIN, y1=INT_MAX, y2=INT_MIN;
        int area=0;
        
        for(auto r: rectangles) {
            x1=min(x1, r[0]);
            y1=min(y1, r[1]);
            x2=max(x2, r[2]);
            y2=max(y2, r[3]);
            
            area+=(r[2]-r[0])*(r[3]-r[1]);
            
            if(!hash.insert(make_pair(r[0],r[1])).second) hash.erase(make_pair(r[0],r[1]));
            if(!hash.insert(make_pair(r[0],r[3])).second) hash.erase(make_pair(r[0],r[3]));
            if(!hash.insert(make_pair(r[2],r[1])).second) hash.erase(make_pair(r[2],r[1]));
            if(!hash.insert(make_pair(r[2],r[3])).second) hash.erase(make_pair(r[2],r[3]));
        }
        
        if(!hash.count(make_pair(x1, y1)) || !hash.count(make_pair(x1, y2)) || !hash.count(make_pair(x2, y1)) || !hash.count(make_pair(x2, y2)) || hash.size()!=4) return false;
        
        return area==(x2-x1)*(y2-y1);
    }
};