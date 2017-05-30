class Solution {
public:
    bool checkRecord(string s) {
        int A=0, L=0;
        for(auto c : s) {
            if(c=='A') {
                L=0;
                A++;
                if(A>1) return false;
            }
            else if(c=='L') {
                L++;
                if(L>2) return false;
            }
            else {
                L=0;
            }
        }
        
        
        return true;
    }
};