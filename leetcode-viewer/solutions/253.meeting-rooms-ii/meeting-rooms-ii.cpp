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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        priority_queue<int, std::vector<int>, std::greater<int> > endtime;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start<b.start;});
        
        endtime.push(intervals[0].end);
        
        for(int i=1; i<intervals.size(); ++i) {
            if(intervals[i].start >= endtime.top()) {
                endtime.pop();
            }
            endtime.push(intervals[i].end);
        }
        return endtime.size();
    }
};