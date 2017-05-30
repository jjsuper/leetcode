class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<string>> hash;
        vector<vector<string>> res;
        
        for(int i=0; i<strings.size(); ++i) {
            string cur=strings[i];
            
            for(int j=cur.size()-1; j>=0; --j) {
                if(cur[j]<cur[0]) cur[j]=cur[j]-cur[0]+'a'+26;
                else cur[j]=cur[j]-cur[0]+'a';
            }
            
            cout << cur << endl;
            
            if(hash.find(cur)==hash.end()) hash[cur]=vector<string>();
            hash[cur].push_back(strings[i]);
        }
        
        
        for(auto it=hash.begin(); it!=hash.end(); ++it) {
            res.push_back(it->second);
        }
        
        return res;
    }
};