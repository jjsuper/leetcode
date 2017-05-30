class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) return false;
        int n=org.size();
        unordered_map<int, unordered_set<int>> edges;
        vector<int> degrees(n+1, 0);
        int cnt=0;
        
        bool flag=false;
        for(int i=0; i<seqs.size(); ++i) {
            for(int j=0; j<seqs[i].size(); ++j) {
                flag=true;
                if(seqs[i][j]>n || seqs[i][j]<=0) return false;
                if(j>0 && !edges[seqs[i][j-1]].count(seqs[i][j])) {
                    edges[seqs[i][j-1]].insert(seqs[i][j]);
                    if(degrees[seqs[i][j]]++==0) cnt++;
                }
            }
        }
        
        if(!flag) return false;
        if(cnt!=n-1) return false;
        
        for(int i=0; i<n; ++i) {
            if(degrees[org[i]]>0) return false;
            for(auto it : edges[org[i]]) {
                if(--degrees[it]==0 && it!=org[i+1])
                    return false;
            }
        }
        
        
        
        return true;
    }
};
