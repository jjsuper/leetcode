class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length+1, 0);
        
        for(int i=0; i<updates.size(); ++i) {
            res[updates[i][0]]+=updates[i][2];
            res[updates[i][1]+1]-=updates[i][2];
        }
        
        for(int i=1; i<length; ++i) {
            res[i]+=res[i-1];
        }
        
        res.pop_back();
        return res;
    }
};