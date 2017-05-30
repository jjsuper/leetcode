class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_set<string> hash;
        int maxX=INT_MIN, minX=INT_MAX;
        
        for(auto p : points) {
            maxX=max(maxX, p.first);
            minX=min(minX, p.first);
            string s=to_string(p.first)+"@"+to_string(p.second);
            hash.insert(s);
        }
        
        int y=maxX+minX;
        for(auto p : points) {
            string s=to_string(y-p.first)+"@"+to_string(p.second);
            if(!hash.count(s))    
                return false;
        }
        
        return true;
    }
};