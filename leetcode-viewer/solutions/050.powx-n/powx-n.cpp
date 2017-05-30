class Solution {
public:
    double myPow(double x, int n) {
        
        long p=(long)n;
        if(n == 0)  return 1;
        if(n < 0 ){
            p=-(long)n;
            x=1/x;
        }
    
        double result = myPow(x,p/2);

    
        if(n % 2 == 0){
            return  result * result;
        }else{
            return  x * result * result ;
        }


    }
};