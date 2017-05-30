class Solution {
public:
    string intToRoman(int num) {
        int list[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string chars[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int i = 0;
        string out="";
        while(num > 0)
        {
            for(;i < 13;i++)
                if(num >= list[i])
                    break;
            out+=chars[i];
            num -= list[i];
        }
        return out;
        
        
        
        
        
    }
};