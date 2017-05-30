class Solution {
public:
    string fractionAddition(string expression) {
        int n=0, d=1;
        int idx=0, p1=0, p2=0;
        
        if(expression[0]!='-') expression="+"+expression;
        while(idx<expression.size()) {
            for(p1=idx+1; p1<expression.size() && expression[p1]!='/'; p1++);
            int nn = stoi(expression.substr(idx+1, p1-idx-1));
            for(p2=p1+1; p2<expression.size() && expression[p2]!='+' && expression[p2]!='-'; p2++);
            int dd = stoi(expression.substr(p1+1, p2-p1-1));
            
            int c = GCD(d, dd);
            n = (n*dd + (expression[idx]=='-'? -1: 1)*d*nn) / c;
            d *= dd/c;
            
            idx=p2;
        }
        
        return to_string(n/GCD(abs(n), d)) + "/" + to_string(d/GCD(abs(n), d));
        
    }
private:
    int GCD(int a, int b) {
        while(b) {
            int tmp=a%b;
            a=b;
            b=tmp;
        }
        return a;
    }
};