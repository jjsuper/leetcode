class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        for(int i=0, prev=0, n=points.size(); i<n; ++i) {
            long cur=det(points[i], points[(i+1)%n], points[(i+2)%n]);
            cout << cur << endl;
            if(cur) {
                if(cur*prev<0) return false;
                else prev=cur;
            }
        }
        return true;
    }
private:
    int det(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) const {
        return (p2[0]-p1[0])*(p3[1]-p2[1])-(p3[0]-p2[0])*(p2[1]-p1[1]);
    }
};