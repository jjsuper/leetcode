class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res;
        if(n == 0)return res;
        for(int pos = 0; pos < strs[0].size(); pos++)//最长前缀的长度不超过strs[0].size()，逐个字符的比较
        {
            for(int k = 1; k < n; k++)//strs[0]的第pos个字符分别和strs[1...n-1]的第pos个字符比较
            {
                if(strs[k].size() == pos || strs[k][pos] != strs[0][pos])
                    return res;
            }
            res.push_back(strs[0][pos]);
        }
        return res;
    }
};