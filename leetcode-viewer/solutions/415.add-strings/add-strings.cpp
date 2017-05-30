class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0, digit=0;
        string res="";
        int i=0;
        
        while(i<num1.size()&&i<num2.size()) {
            digit=(num1[num1.size()-1-i]-'0'+num2[num2.size()-1-i]-'0'+carry)%10;
            carry=(num1[num1.size()-1-i]-'0'+num2[num2.size()-1-i]-'0'+carry)/10;
            cout << digit << carry << endl;
            res+=to_string(digit);
            ++i;
        }
        
        while(i<num1.size()) {
            digit=(num1[num1.size()-1-i]-'0'+carry)%10;
            carry=(num1[num1.size()-1-i]-'0'+carry)/10;
            res+=to_string(digit);
            ++i;
        }
        
        while(i<num2.size()) {
            digit=(num2[num2.size()-1-i]-'0'+carry)%10;
            carry=(num2[num2.size()-1-i]-'0'+carry)/10;
            res+=to_string(digit);
            ++i;
        }
        
        if(carry) res+=to_string(carry);
        
        
        reverse(res.begin(),res.end());
        return res;
    }
};