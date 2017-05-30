class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int radius=INT_MIN;
        for(auto house:houses) {
            int pos=lower_bound(heaters.begin(), heaters.end(), house)-heaters.begin();
            
            int left=pos>0? house-heaters[pos-1]: INT_MAX;
            int right=pos<heaters.size()? heaters[pos]-house: INT_MAX;
            
            radius=max(radius, min(left,right));
        }
        
        return radius;
    }
};