class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        
        unordered_map<string, unordered_map<string, double>> matrix;
        vector<double> res;

        for(int i=0; i<equations.size(); ++i) {
            matrix[equations[i].first][equations[i].first]=1.0;
            matrix[equations[i].second][equations[i].second]=1.0;
            matrix[equations[i].first][equations[i].second]=values[i];
            matrix[equations[i].second][equations[i].first]=1/values[i];
        }
   
   
        for(auto it : queries) {
            unordered_set<string> s;
            double tmp=dfs(it.first, it.second, matrix, s);
            if(tmp)
                res.push_back(tmp);
            else 
                res.push_back(-1.0);
        }
        
        
        return res;
    }
private:
    double dfs(string start, string end, unordered_map<string, unordered_map<string, double>>& matrix, unordered_set<string>& s) {
        if(matrix[start].count(end)) return matrix[start][end];
        
        for(auto it : matrix[start]) {
            if(!s.count(it.first)) {
                s.insert(it.first);
                double tmp=dfs(it.first, end, matrix, s);
                s.erase(it.first);
                if(tmp) return tmp*it.second;
            }
        }
        return 0.0;
    }
};


 