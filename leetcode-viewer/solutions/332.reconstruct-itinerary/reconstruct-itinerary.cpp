class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
        for(auto it: tickets) {
            targets[it.first].insert(it.second);
        }
        
        visited("JFK");
        reverse(results.begin(), results.end());
        return results;
    }
private:
    map<string, multiset<string>> targets;
    vector<string> results;
    
    void visited(string from) {
        while(!targets[from].empty()) {
            string to = *targets[from].begin();
            targets[from].erase(targets[from].begin());
            visited(to);
        }
        results.push_back(from);
    } 
};