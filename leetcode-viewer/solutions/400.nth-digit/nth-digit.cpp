class Solution {
public:
    int findNthDigit(int n) {
        long base = 9, digits = 1;
        while(n-base*digits>0) {
            n -= base*digits;
            digits++;
            base *= 10;
        }
        
        /*int num=-1;
        for(int i=1; i<digit; ++i) {
            base /= 10;
            num += base;
        }
        int index=n/digit;
        if(n==0) {num--; digit--;}
        //else if(num==0) num=index+num;
        else num=index+1+num;
        
        cout << num;
        
        index=n%digit;
        if(index==0) return num%10;
        for(int i=digit; i>index; --i) {
            num /= 10;
        }
        
        return num%10;*/
        // step 2. calculate what the muber is.
        int index = n % digits;
        if (index == 0)
            index = digits;
        long num = 1;
        for (int i = 1; i < digits; i ++)
            num *= 10;
        num += (index == digits) ? n / digits - 1 : n / digits;

        // step 3. find out which digit in the number is we want.
        for (int i = index; i < digits; i ++)
            num /= 10;
        return num % 10;
    }
};