class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, 0);
        int cnt=n;
        
        for(int i=0; i<n; ++i) roots[i]=i;
        
        for(int i=0; i<edges.size(); ++i) {
            int root1=findroot(roots, edges[i].first);
            int root2=findroot(roots, edges[i].second);
            if(root1!=root2) {
                roots[root1]=root2;
                cnt--;
            }
        }
        return cnt;
    }
private:
    int findroot(vector<int>& roots, int id) {
        while(roots[id]!=id) {
            roots[id]=roots[roots[id]];
            id=roots[id];
        }
        return id;
    }
};