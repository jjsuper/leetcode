class Solution {
public:
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    vector<vector<string>> res;         
    unordered_map<string, vector<string>> nodeNeighbors;    // Neighbors for every node
    unordered_map<string, int> distance;    // Distance of every node from the start node
    vector<string> solution;
  
  
    // BFS: Trace every node's distance from the start node (level by level).
    queue<string> q;
    q.push(beginWord);
    distance[beginWord]=0;
    bool foundEnd=false;
    
    while(!q.empty()&&!foundEnd) {
        int n=q.size();
        unordered_set<string> used;
        for(int i=0; i<n; ++i) {
            string cur=q.front();
            q.pop();
            int curDist=distance[cur];
            vector<string> neighbors = getNeighbors(cur, dict);
            //nodeNeighbors[cur]=neighbors;
            for(string next: neighbors) {
                used.insert(next);
                if (!distance.count(next)) {// Check if visited
                    nodeNeighbors[cur].push_back(next); 
                    distance[next]=curDist+1;
                    if (endWord==next)// Found the shortest path
                        foundEnd=true;
                    else
                        q.push(next);
                }
                else {
                    if(distance[next]==curDist+1)
                        nodeNeighbors[cur].push_back(next); 
                }
            }
        }
        
        for(string u: used) {
            dict.erase(u);
        }
    }
    
    dfs(beginWord, endWord, nodeNeighbors, distance, solution, res);   
    return res;
}




// Find all next level nodes.    
vector<string> getNeighbors(string node, unordered_set<string>& dict) {
    vector<string> res;
    for(int i=0; i<node.size(); ++i) {
        for(char c='a'; c<='z'; ++c) {
            if(c==node[i]) continue;
            string nnode=node;
            nnode[i]=c;
            if(dict.count(nnode)) {
                res.push_back(nnode);
            }
        }
    }
    return res;
}

// DFS: output all paths with the shortest distance.
void dfs(string cur, string end, unordered_map<string, vector<string>>& nodeNeighbors, unordered_map<string, int>& distance, vector<string> &solution, vector<vector<string>>& res) {
    solution.push_back(cur);
    if(cur==end) {
        res.push_back(solution);
    }
    else {
        for(string next: nodeNeighbors[cur]) {
        if(distance[next]==distance[cur]+1) 
            dfs(next, end, nodeNeighbors, distance, solution, res);
        }
    }
    solution.pop_back();
}

};