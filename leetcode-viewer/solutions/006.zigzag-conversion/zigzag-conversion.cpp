class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        
        
        int dev=2*(numRows-1);
        
        string row[numRows];
        
        for(int i=0;i<s.size();++i)
        {
            int rem=i%dev;
            
            if(rem>dev/2)
            {
                rem=dev-rem;
            }
            
            row[rem]=row[rem]+s[i];
            
        }
        
        string res;
        for(int i=0;i<numRows;++i)
        {
            res=res+row[i];
        }
        
        return res;
    }
};