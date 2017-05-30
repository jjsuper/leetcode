class Solution {
public:
    bool isPowerOfThree(int n) {
          double logRes = log10(n)/log10(3);
  return (logRes - int(logRes) == 0) ? true : false; 
    }
};