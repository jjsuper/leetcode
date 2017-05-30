class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i=0; i<num.size()/2; ++i)
            for(int j=i+1; j<num.size(); ++j) {
                string n1=num.substr(0, i+1);
                string n2=num.substr(i+1, j-i);
                string n3=num.substr(j+1);
                if(check(n1, n2, n3)) return true;
            }
        return false;
    }

private:
    bool check(string n1, string n2, string n3) {
        if(n1.size()>1 && n1[0]=='0' || n2.size()>1 && n2[0]=='0') return false;
        string sum=add(n1, n2);
        if(n3==sum) return true;
        if(n3.size()<sum.size() || n3.substr(0, sum.size())!=sum) return false;
        return check(n2, sum, n3.substr(sum.size()));
    }

    string add(string a, string b) {
        string res;
        int i=a.size()-1, j=b.size()-1, carry=0;
        while(i>-1||j>-1) {
            int sum=carry+(i>-1? a[i--]-'0': 0)+(j>-1? b[j--]-'0': 0);
            res=to_string(sum%10)+res;
            carry=sum/10;
        }
        if(carry) res=to_string(carry)+res;
        return res;
    }
};