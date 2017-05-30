class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> mymap;
        map<char, string>::iterator it;
    
    
    stringstream ss(str);
    string s;
    vector<string> vec;
    while(ss >> s)
    {   
         vec.push_back(s);
    }  
    
    //cout << pattern.size() << ' ' << vec.size();
    
    if(pattern.size()!=vec.size()) return false;
    
    
        for(int i=0;i<pattern.size();++i)
        {
            it=mymap.find(pattern[i]);
            if(it!=mymap.end())
            {
                if(it->second!=vec[i])  
                {
                    cout << '1';
                    return false;
                }
            }
            else
            {
                for(it=mymap.begin();it!=mymap.end();++it)
                {
                    if(it->second==vec[i])
                    {
                        cout << '2';
                        return false;
                    }
                }
                mymap.insert(pair<char, string>(pattern[i], vec[i]));                
            }
        }
        
        
        return true;
    }
};