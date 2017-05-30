class Solution {
public:
    string convertToTitle(int n) {
        
        string ret="";
        int m;
        //n--;
        
        do
        {
            n--;
            m= n%26;
            n=n/26;
            
            
            ret = char(m+'A') + ret;
            
            
        }while(n!=0);
    
        return ret;
    }
};