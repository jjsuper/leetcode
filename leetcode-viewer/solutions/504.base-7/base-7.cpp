class Solution {
public:
    string convertToBase7(int num) {
        string res="";
        if(num==0) return "0";
        int n=num>0? num: -num;
        
        
        while(n>0) {
            res=std::to_string(n%7)+res;
            n=n/7;
        }
        
        
        return num>0? res: "-"+res;
    }
};