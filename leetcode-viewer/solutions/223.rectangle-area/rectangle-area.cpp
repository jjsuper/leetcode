class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l = min(max(A, E), C);
        int r = min(max(A, G), C);
        int t = min(max(B, H), D);
        int b = min(max(B, F), D);
        return (C-A)*(D-B) + (G-E)*(H-F) - (r-l)*(t-b);
        
        
    }
};