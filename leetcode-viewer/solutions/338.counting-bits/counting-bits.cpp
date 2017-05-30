class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        int i=0;
        
        while(i<num)
        {
            int size=res.size();
            for(int j=0;j<size;++j)
            {
                if(i<num)
                {
                    i++;
                    res.push_back(res[j]+1);
                }
                else 
                    return res;
            }
            
        }
        
        
        return res;
    }
};