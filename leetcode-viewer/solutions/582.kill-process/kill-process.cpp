class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> hash;
        vector<int> res;
        
        for(int i=0; i<pid.size(); ++i) {
            hash[ppid[i]].push_back(pid[i]);
        }
        
        queue<int> q;
        q.push(kill);
        while(!q.empty()) {
            int cur=q.front();
            res.push_back(cur);
            q.pop();
            for(auto n : hash[cur]) {
                q.push(n);
            }
        }
        
        
        return res;
    }
};