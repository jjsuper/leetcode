class Solution {
public:
    string toHex(int num) {
        string res="";
        if(!num) return "0";
        int count =0;
        while(num&&count<8) {
            int tmp = num & 15;
            if(tmp<10) res+=to_string(tmp);
            else res+='a'+tmp-10;
            num = num >> 4;
            count++;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};