class Solution {
public:
    int numWays(int n, int k) {
        if(n<2||k==0) return n*k;
        
        int a=k, b=k*(k-1);
        
        for(int i=2; i<n; ++i) {
            int tmp=(k-1)*(a+b);
            a=b;
            b=tmp;
        }
        return a+b;
    }
};