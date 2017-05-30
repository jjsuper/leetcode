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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int idx=0;
        for(; idx<intervals.size() && intervals[idx].end<newInterval.start; ++idx) {
            res.push_back(intervals[idx]);
        }
        
        for(; idx<intervals.size() && newInterval.end>=intervals[idx].start ; ++idx) {
            newInterval.start=min(newInterval.start, intervals[idx].start);
            newInterval.end=max(newInterval.end, intervals[idx].end);
        }
        res.push_back(newInterval);
        
        
        for(; idx<intervals.size(); ++idx) {
            res.push_back(intervals[idx]);
        }
        
        return res;
    }
};