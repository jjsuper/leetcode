class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxlen = -1;
        for (int i = 0; i < strs.size(); ++i) {
            bool flag=true;
            for (int j = 0; j < strs.size(); ++j) {
                if (i != j && isSub(strs[i], strs[j])) {
                    flag=false;
                    break;
                }
            }
            if (flag == true) {
                maxlen = max((int)strs[i].size(), maxlen);
            }
        }
        return maxlen;
    }
private:
    bool isSub(string a, string b) {
        if (a.empty()) return true;
        int i=0, j=0;
        while(i<a.size() && j<b.size()) {
            if(a[i]==b[j]) {
                i++; j++;
            }
            else {
                j++;   
            }
        }
        return i==a.size();
    }
};