class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend==INT_MIN && divisor==-1)) return INT_MAX;
        int sign=(dividend<0 ^ divisor<0)? -1: 1;
        long dvd=labs(dividend);
        long dvs=labs(divisor);
        int res=0;
        
        while(dvd>=dvs) {
            long tmp=dvs, mult=1;
            while(dvd>=(tmp<<1)) {
                tmp<<=1;
                mult<<=1;
            }
            dvd-=tmp;
            res+=mult;
        }
        
        return sign<0? -res: res;
    }
};