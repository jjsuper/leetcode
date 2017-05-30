class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //unordered_set<string> words(wordList.begin(), wordList.end());
        //words.insert(endWord);
        vector<bool> visited(wordList.size(), 0);
        queue<string> q;
        
        q.push(beginWord);
        int dist=2;
        
        while(!q.empty()) {
            int n=q.size();
            
            for(int i=0; i<n; ++i) {
                string cur=q.front();
                q.pop();
                //cout << cur;
                vector<string> next=findNext(cur, wordList, visited);
                
                for(int j=0; j<next.size(); ++j) {
                    if(next[j]==endWord) return dist;
                    q.push(next[j]);
                }
                
            }
            
            dist++;
            
        }
        
        
        
        return 0;
    }
    
private:
    vector<string> findNext(string s, vector<string>& wordList, vector<bool>& visited) {
        vector<string> res;
        for(int i=0; i<wordList.size(); ++i) { 
            if(!visited[i]) {
                int cnt=0;
                for(int j=0; j<s.size(); ++j) {
                    cnt+= (s[j]!=wordList[i][j]);
                }
                if(cnt==1) {
                    visited[i]=1;
                    res.push_back(wordList[i]);
                }
            }
        }
        return res;
    }
    
};