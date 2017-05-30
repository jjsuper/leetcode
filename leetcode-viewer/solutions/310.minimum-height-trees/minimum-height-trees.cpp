class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n==1) return vector<int>({0});
        unordered_map<int, unordered_set<int>> adj;
        vector<int> leaves;
        
        for(auto it: edges) {
            adj[it.first].insert(it.second);
            adj[it.second].insert(it.first);
        }
        
        for(auto it: adj) {
            if(it.second.size()==1) leaves.push_back(it.first);
        }
        
        while(n>2) {
            n-=leaves.size();
            vector<int> newleaves;
            for(auto it: leaves) {
                for(auto next: adj[it]) {
                    adj[next].erase(it);
                    if(adj[next].size()==1) newleaves.push_back(next);
                }
            }
            leaves.clear();
            leaves=newleaves;
        }
        return leaves;
    }
};