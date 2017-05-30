class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n,n);
    }
private:
    vector<string> helper(int n, int m) {
        vector<string> res;
        if(n==0) return vector<string>{""};
        if(n==1) return vector<string>{"1", "0", "8"};
        
        vector<string> list=helper(n-2, m);
        for(int i=0; i<list.size(); ++i) {
            if(n!=m) res.push_back("0"+list[i]+"0");
            res.push_back("1"+list[i]+"1");
            res.push_back("8"+list[i]+"8");
            res.push_back("6"+list[i]+"9");
            res.push_back("9"+list[i]+"6");
        }
        return res;
    }
    
};