class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.empty()) return "";
        //if(words.size()==1) return words[0].substr(0,1);
        int cnt_edge=0;
        unordered_set<char> chars;
        
        for(int i=0; i<words.size()-1; ++i) {
            chars.insert(words[i].begin(), words[i].end());
            for(int j=0; j<words[i].size(); ++j) {
                if(words[i][j]!=words[i+1][j]) {
                    if(inedge.find(words[i][j])==inedge.end()) inedge[words[i][j]]=0;
                    if(!outedge[words[i][j]].count(words[i+1][j])) {
                        inedge[words[i+1][j]]++;
                        outedge[words[i][j]].insert(words[i+1][j]);
                        cnt_edge++;
                    }
                    break;
                }
            }
        }    
        chars.insert(words[words.size()-1].begin(), words[words.size()-1].end());
        
        
        //topological sort
        string res;
        queue<char> q;
        
        for(auto x: chars) {
            cout << x << inedge[x] << endl;
            if(inedge[x]==0) q.push(x);
        }
        
        while(!q.empty()) {
            char tmp=q.front();
            q.pop();
            res+=tmp;
            cnt_edge-=outedge[tmp].size();
            for(char c: outedge[tmp]) {
                inedge[c]--;
                if(inedge[c]==0) q.push(c);
            }
        }
        
        
        return cnt_edge==0? res: "";
    }
private:
    unordered_map<char, int> inedge;
    unordered_map<char, unordered_set<char>> outedge;
    
};