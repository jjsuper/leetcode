class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.empty()) return res;
        helper(res, "", num, target, 0, 0, 0);
        return res;
    }
private:
    void helper(vector<string>& res, string path, string num, int target, int pos, long cur, long prev) {
        if(pos==num.size()) {
            if(cur==target)
                res.push_back(path);
                return;
        }
        
        for(int i=pos; i<num.size(); ++i) {
            if(num[pos]=='0' && i>pos) break;
            string _str=num.substr(pos, i-pos+1);
            long _value=stol(_str);
            if(pos==0) {
                helper(res, path+_str, num, target, i+1, _value, _value);
            }
            else {
                helper(res, path+"+"+_str, num, target, i+1, cur+_value, _value);
                helper(res, path+"-"+_str, num, target, i+1, cur-_value, -_value);
                helper(res, path+"*"+_str, num, target, i+1, cur-prev+prev*_value, prev*_value);
            }
        }
    }
};