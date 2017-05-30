class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        int dig;
        int rev=0;
        
        while(num>0)
        {
            dig=num%10;
            rev=rev*10+dig;
            num=num/10;
        }
        
        return rev==x;
    }
};