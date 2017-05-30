class Solution {
public:
    string countAndSay(int n) {
        string result="";   
        
        if(n<0) return result;
        
        result = "1";
        
        for(int i=0; i<n-1; ++i)
        {
            string tmp="";
            int count = 1;
            
            for(int j=0; j<result.length();j++)
            {
                
                if(result[j]==result[j+1])
                {
                    count++;
                }
                else
                {
                    tmp = tmp + char(count+'0') + result[j];
                    count = 1;
                }
            }
            
            
            result = tmp;
        }
        
        
        return result;
        
    }
};