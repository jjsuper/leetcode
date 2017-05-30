class Solution {
public:
    int calculate(string s) {
        stack<int> mystack;
        int res=0;
        int num=0;
        int sign=1;
        
        for(int i=0; i<s.size(); ++i) {
            if(isdigit(s[i])) {
                num=num*10+s[i]-'0';
            }
            else if(s[i]=='+') {
                res=res+sign*num;
                num=0;
                sign=1;
            }
            else if(s[i]=='-') {
                res=res+sign*num;
                num=0;
                sign=-1;
            }
            else if(s[i]=='(') {
                mystack.push(res);
                mystack.push(sign);
                res=0;
                sign=1;
            }
            else if(s[i]==')') {
                res=res+sign*num;
                num=0;
                res*=mystack.top();
                mystack.pop();
                res+=mystack.top();
                mystack.pop();
            }
        }
        if(num!=0) res+=sign*num;
        
        return res;
    }
};