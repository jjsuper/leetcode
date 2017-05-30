class Solution {
public:
    int hammingDistance(int x, int y) {
        int dis=x^y;
        int cnt=0;
        for(int i=0; i<32; ++i) {
            cnt+= dis & 1? 1: 0;
            dis=dis>>1;
        }
        
        return cnt;
    }
};