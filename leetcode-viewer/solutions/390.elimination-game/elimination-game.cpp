class Solution {
public:
    int lastRemaining(int n) {
        if (n==1) return 1;
        int p = lastRemaining(n/2);
        return (n/2 - p + 1) * 2;
    }
};