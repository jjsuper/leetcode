class Solution {
public:
    int trailingZeroes(int n) {
        
    if(n<=0) return 0;

    int numZero=0;
    while(n>0){
        numZero+=n/5;
        n=n/5;
    }
    return numZero;
        
    }
};