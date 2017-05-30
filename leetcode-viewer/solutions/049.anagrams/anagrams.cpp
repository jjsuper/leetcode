class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<string, vector<string>> mymap;
        std::map<string, vector<string>>::iterator it;
        
        
        for(int i=0; i<strs.size(); ++i)
        {
            string key=strs[i];
            std::sort(key.begin(), key.end());
            it=mymap.find(key);
            
            if(it!= mymap.end())
            {
                it->second.push_back(strs[i]);
            }
            else
            {
                vector<string> vstr;
                vstr.push_back(strs[i]);
                mymap.insert(std::pair<string, vector<string>>(key,vstr));
            }
        }
        
        vector<vector<string>> res;
        for(it=mymap.begin(); it!=mymap.end(); ++it)
        {
            res.push_back(it->second);
        }
        
        
        return res;
    }
};