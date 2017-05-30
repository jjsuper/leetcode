class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        int num1, num2, num3;
        
        for(string token: tokens) {
            if(token=="+") {
                num2=num.top(); num.pop();
                num1=num.top(); num.pop();
                num3=num1+num2; num.push(num3);
            }
            else if(token=="-") {
                num2=num.top(); num.pop();
                num1=num.top(); num.pop();
                num3=num1-num2; num.push(num3);
            }
            else if(token=="*") {
                num2=num.top(); num.pop();
                num1=num.top(); num.pop();
                num3=num1*num2; num.push(num3);
            }
            else if(token=="/") {
                num2=num.top(); num.pop();
                num1=num.top(); num.pop();
                num3=num1/num2; num.push(num3);
            }
            else {
                num3=stoi(token); num.push(num3);
            }
        }
        
        
        return num.top();
    }
};