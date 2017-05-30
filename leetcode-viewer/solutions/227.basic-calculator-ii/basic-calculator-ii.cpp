class Solution {
public:
    int calculate(string s) {
        istringstream in('+'+s+'+');
        int res=0, tmp=0, n;
        char op;
        while(in>>op) {
            if(op=='+') {
                res+=tmp;
                in>>tmp;
            }
            else if(op=='-') {
                res+=tmp;
                in>>tmp;
                tmp=-tmp;
            }
            else if(op=='*') {
                in>>n;
                tmp *= n;
            }
            else {
                in>>n;
                tmp /= n;
            }
        }
        
        
        return res;
    }
};