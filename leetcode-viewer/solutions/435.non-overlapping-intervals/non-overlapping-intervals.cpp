/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        
        sort(intervals.begin(),intervals.end(),[](Interval& i1, Interval& i2){
           return i1.start<i2.start || (i1.start==i2.start && i1.end<i2.end);
        });
        
        int cnt=0;
        for(int i=1; i<intervals.size(); ++i) {
            if(intervals[i].start < intervals[i-1].end){
                cnt++;
                intervals[i].end = min(intervals[i].end, intervals[i-1].end);
            }
        }
        
        return cnt;
    }
};