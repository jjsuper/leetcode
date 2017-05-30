class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int count=0;
        for(int len=low.size(); len<=high.size(); ++len) {
            string cur(len, '0');
            helper(low, high, cur, 0, len-1, count);
        }
        return count;
    }
private:
    vector<vector<char>> pairs={{'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}, {'0', '0'}};
    void helper(string low, string high, string cur, int left, int right, int& count) {
        if(left>right) {
            if((cur.size()==low.size() && cur<low) || (cur.size()==high.size() && high<cur)) return;
            count++;
            return;
        }
        for(auto p:pairs) {
            cur[left]=p[0];
            cur[right]=p[1];
            if(cur.size()!=1 && cur[0]=='0') continue;
            if(left==right && p[0]!=p[1]) continue;
            helper(low, high, cur, left+1, right-1, count);
        }
    }
};
/*
bool operator<(const string& a, const string& b) {
    if(a.size()<b.size()) return true;
    if(a.size()>b.size()) return false;
    for(int i=0; i<a.size(); ++i) {
        if(a[i]<b[i]) return true;
        if(a[i]>b[i]) return false;
    }
    return false;
}*/