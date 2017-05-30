class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        
        int maxsize=max(a.size(),b.size());
        int c=0;
        int out=0;
        
        for(int i=0;i<maxsize;++i)
        {
            int ai, bi;
            if(i>=a.size())
            {
                ai=0;
            }
            else
            {
                ai=a[a.size()-i-1]-'0';
            }
            if(i>=b.size())
            {
                bi=0;
            }
            else
            {
                bi=b[b.size()-i-1]-'0';
            }
            
            out=(ai+bi+c)%2;
            c=(ai+bi+c)/2;
            
            sum=to_string(out)+sum;
        }
        
        
        if(c)
        {
            sum=to_string(c)+sum;
        }
        
        return sum;
    }
};