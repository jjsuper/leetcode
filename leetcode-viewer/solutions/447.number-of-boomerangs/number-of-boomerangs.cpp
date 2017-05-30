class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if(points.empty()) return 0;
        int res=0;
        
        for(auto i: points) {
            map<int, int> hash;
            for(auto j: points) if(i!=j){
                int x=i.first-j.first;
                int y=i.second-j.second;
                int dist=x*x+y*y;
                if(hash.find(dist)==hash.end()) {
                    hash[dist]=0;
                }
                hash[dist]++;
            }
            for(auto it: hash) {
                if(it.second>=2) res+=it.second*(it.second-1);
            }
        }
    
        return res;
    }
};