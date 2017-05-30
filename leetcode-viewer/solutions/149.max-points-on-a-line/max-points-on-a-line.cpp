/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res=0;
        
        for(int i=0; i<points.size(); ++i) {
            map<pair<int, int>, int> hash;
            int localmax=0, vertical=0, overlap=0;
            
            for(int j=i+1; j<points.size(); ++j) {
                if(points[i].x==points[j].x && points[i].y==points[j].y) {
                    overlap++;
                }
                else if(points[i].x==points[j].x) {
                    vertical++;
                }
                else {
                    int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
                    int gcd=GCD(a, b);
                    a/=gcd;
                    b/=gcd;
                    
                    hash[make_pair(a,b)]++;
                    localmax=max(localmax, hash[make_pair(a,b)]);
                }
            }
            localmax=max(localmax, vertical);
            
            res=max(res, localmax+overlap+1);
        }
        
        return res;
    }
private:
    int GCD(int a, int b) {
        if(b==0) return a;
        return GCD(b, a%b);
    }
};