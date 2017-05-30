class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;
        int total=0, begin=timeSeries[0];
        for(auto it:timeSeries) {
            total += it<begin+duration ? it-begin : duration;
            begin=it;
        }

        return total+duration;
    }
};