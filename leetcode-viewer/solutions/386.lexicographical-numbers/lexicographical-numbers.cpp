class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        recurse(1, n, res);
        return res;
    }
private:
    void recurse(int target, int n, vector<int>& res) {
        if(target>n) return;
        res.push_back(target);
        recurse(target*10, n, res);
        if(target%10!=9) recurse(target+1, n, res);
    }
};