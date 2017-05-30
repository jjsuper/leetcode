class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n<1) return 1;
        if(n>10) n=10;
        
        int accum=9;
        int factor=9;
        int count=10;
        
        for(int i=1; i<n; ++i)
        {
            accum*=factor;
            count+=accum;
            factor--;
        }
        
        
        return count;
        
        
    }
};