class Solution {
public:
    int numSquares(int n) {
        if(n<=0)
        {
            return 0;
        }
        
        vector<int> cntPerfectSquares(1,0);
        
        while(cntPerfectSquares.size()<=n)
        {
            int cntSquare=INT_MAX;
            for(int i=1; i*i<=cntPerfectSquares.size(); ++i)
            {
                cntSquare = min(cntSquare, cntPerfectSquares[cntPerfectSquares.size()-i*i]+1);
            }
            
            cntPerfectSquares.push_back(cntSquare);
        }
        
        
        return cntPerfectSquares[n];
        
        
    }
};