// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int floor, ceiling, midpoint, lastBadVersion;

    floor = 1;
    ceiling = n;
    while (floor <= ceiling) {
        midpoint = floor + (ceiling - floor) / 2;
        if (isBadVersion(midpoint)) {
            ceiling = midpoint - 1;
            lastBadVersion = midpoint;
        } else {
            floor = midpoint + 1;
        }
    }
    return lastBadVersion;
    
        
        
        
    }
};