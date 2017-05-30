class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int mindiff=INT_MAX, n=timePoints.size();
        
        for(int i=0; i<timePoints.size(); ++i) {
            int diff=(stoi(timePoints[i].substr(0,2))-stoi(timePoints[(i-1+n)%n].substr(0,2)))*60+stoi(timePoints[i].substr(3,2))-stoi(timePoints[(i-1+n)%n].substr(3,2));
            cout << diff << endl;
            diff=diff<0? 1440+diff: diff;
            mindiff=min(mindiff, diff);
        }
        return mindiff;
    }
};