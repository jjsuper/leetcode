class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int res=0;
        if(points.empty()) return res;
        sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first || (a.first == b.first && a.second < b.second); 
        });
        
        int left=points[0].first, right=points[0].second;
        res=1;
        for(auto it : points) {
            if(it.first<=right) {
                left=max(left, it.first);
                right=min(right, it.second);
            }
            else {
                res++;
                left=it.first;
                right=it.second;
            }
        }
        
        return res;
    }
};