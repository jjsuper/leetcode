class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> array;
        
        for(auto i:nums)
            array.push_back(to_string(i));
        sort(array.begin(), array.end(), [](string &s1, string &s2){ return s1+s2>s2+s1;});
        
        string res;
        for(auto i:array)
            res+=i;
        
        while(res[0]=='0' && res.size()>1)
            res.erase(0,1);
        
        
        return res;
    }
};