class Solution {
public:
    int romanToInt(string s) {
        std::map<char,int> roman={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int num=0;
        int last=0;
        int current=0;
        
        for(int i=0;i<s.size();++i)
        {
           current=roman[s[i]];
           if(last<current)
           {
               num=num+current-2*last;
           }
           else
           {
               num+=current;
           }
           last=current;
        }
        
        return num;
    }
    
};