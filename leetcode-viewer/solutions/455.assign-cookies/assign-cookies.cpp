class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt=0;
        
        for(int i=0, j=0; i<g.size() && j<s.size(); ) {
            if(s[j]>=g[i]) {cnt++; i++; j++;}
            else j++;
        }
        
        
        return cnt;
    }
};