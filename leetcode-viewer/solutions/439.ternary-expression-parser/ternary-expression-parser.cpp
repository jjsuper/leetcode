class Solution {
public:
    string parseTernary(string expression) {
        if(expression.empty()) return "";
        stack<char> s;  
        
        for(int i=expression.size()-1; i>-1; i--) {
            if(!s.empty() && s.top()=='?') {
                s.pop();
                char first=s.top();
                s.pop();
                s.pop();
                char second=s.top();
                s.pop();

                if(expression[i]=='T') s.push(first);
                else s.push(second);
            }
            else {
                s.push(expression[i]);
            }
        }
        
        string res(1, s.top());
        
        return res;
    }
};