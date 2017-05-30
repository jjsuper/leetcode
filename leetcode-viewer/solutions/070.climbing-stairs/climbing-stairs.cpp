class Solution {
public:
    int climbStairs(int n) {
        /*
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        
        return climbStairs(n-1)+climbStairs(n-2);
     */
    if(n<=0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
     
     int num1=1, num2=2, num;
     
     for(int i=3;i<=n;++i)
     {
         num=num1+num2;
         num1=num2;        
         num2=num;
     }
     
     return num;
     
    }
};