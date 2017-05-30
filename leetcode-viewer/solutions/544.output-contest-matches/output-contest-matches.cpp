class Solution {
public:
    string findContestMatch(int n) {
        vector<string> s;
        for(int i=1; i<=n; ++i) s.push_back(to_string(i));
        vector<string> tmp=recursion(s);
        return tmp[0];
    }
private:
    vector<string> recursion(vector<string> s) {
        if(s.size()==1) return s;
        int n=s.size();
        vector<string> res;
        
        for(int i=0; i<n/2; ++i) {
            string tmp="("+s[i]+","+s[n-1-i]+")";
            res.push_back(tmp);
        }
        
        return recursion(res);
    }
};