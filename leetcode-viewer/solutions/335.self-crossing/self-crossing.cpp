class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        // Categorize the self-crossing scenarios, there are 3 of them: 
        // 1. Fourth line crosses first line and works for fifth line crosses second line and so on...
        // 2. Fifth line meets first line and works for the lines after
        // 3. Sixth line crosses first line and works for the lines after
        if(x.size()<4) return false;
        
        for(int i=3; i<x.size(); ++i) {
            if(x[i]>=x[i-2] && x[i-3]>=x[i-1]) return true;
            if(i>3 && x[i-1]==x[i-3] && x[i]+x[i-4]>=x[i-2]) return true;
            if(i>4 && x[i-3]>=x[i-1] && x[i-1]+x[i-5]>=x[i-3] && x[i-4]+x[i]>=x[i-2] && x[i-2]>=x[i-4]) return true; 
        }
        
        return false;
    }
};