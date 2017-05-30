class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        /*

 Input: 4
[[0,1],[2,3],[1,2]]
Output: false
Expected: true 
        unordered_set<int> num;
        for(int i=0; i<n; ++i)
            num.insert(i);
        for(int i=0; i<edges.size(); ++i) {
            if(num.find(edges[i].first)==num.end() && num.find(edges[i].second)==num.end()) return false;
            if(num.find(edges[i].first)!=num.end()) num.erase(edges[i].first);
            if(num.find(edges[i].second)!=num.end()) num.erase(edges[i].second);
        }
        return edges.size()==n-1;
        */
        
        vector<int> node(n, 0);
        for(int i=0; i<n; ++i) node[i]=i; 
        for(int i=0; i<edges.size(); ++i) {
            int f=edges[i].first;
            int s=edges[i].second;
            while(node[f]!=f) f=node[f];
            while(node[s]!=s) s=node[s];
            if(f==s) return false;
            node[s]=f;
        }
        return edges.size()==n-1;
        
    }
};