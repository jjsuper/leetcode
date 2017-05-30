class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
    
        for(int i=0; i<s.length(); ++i) {
            if(s[i]=='(') mystack.push(')');
            else if(s[i]=='[') mystack.push(']');
            else if(s[i]=='{') mystack.push('}');
            else {
                    if(mystack.empty()) return false;
                    else if(mystack.top()!=s[i]) return false;
                    else  mystack.pop();
            }
        }
        
        return mystack.empty();
    }
};