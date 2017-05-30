class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> ret;
        vector<int> subset;
        
        for(int i=0; i<(1<<S.size());++i)
        {
            subset.clear();
            for(int j=0; j<S.size();++j)
            {
                if((1<<j)&i)
                    subset.push_back(S[j]);
            }
            sort(subset.begin(),subset.end());
            ret.push_back(subset);

        }
        
        
        
        
        return ret;
    }
};