class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0) return false;
        
        int cmp=1;
        
        for(int i=0;i<16;++i)
        {
            if(!(cmp^num)) return true;
            cmp=cmp<<2;
        }
        
        
        
        return false;
    }
};