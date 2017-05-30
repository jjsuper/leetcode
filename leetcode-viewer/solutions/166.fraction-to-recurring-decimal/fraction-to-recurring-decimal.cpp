class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string res;
        if(numerator<0 ^ denominator<0) res+='-';
        long num=numerator<0? (long)numerator*(-1): (long)numerator;
        long denom=denominator<0? (long)denominator*(-1): (long)denominator;
        long integral=num/denom;
        res+=to_string(integral);
        long rmd=num%denom;
        if(!rmd) return res;
        res+='.';
        rmd*=10;
        unordered_map<long, long> mp;
        while(rmd) {
            long quotient=rmd/denom;
            if(mp.find(rmd)!=mp.end()) {
                res.insert(mp[rmd], 1, '(');
                res+=')';
                break;
            }
            mp[rmd]=res.size();
            res+=to_string(quotient);
            rmd=(rmd%denom)*10;
        }
        return res;
    }
};