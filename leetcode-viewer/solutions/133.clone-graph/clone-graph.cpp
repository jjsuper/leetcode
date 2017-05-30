/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        if(visited.find(node->label)!=visited.end()) 
            return visited[node->label];
        UndirectedGraphNode *ret=new UndirectedGraphNode(node->label);
        visited[node->label]=ret;
        for(auto neighbor: node->neighbors)
            ret->neighbors.push_back(cloneGraph(neighbor));
        
        return ret;
    }
private:
    unordered_map<int, UndirectedGraphNode*> visited;
};