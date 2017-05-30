// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int ans;
        int left=1, right=n;
        
        while(left<=right)
        {
            ans=left+(right-left)/2;
            if(guess(ans)==0) return ans;
            else if(guess(ans)==-1) right=ans-1;
            else left=ans+1;
        }
        
        
        return ans;
    }
};