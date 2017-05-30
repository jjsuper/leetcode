class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask;
        int ret=0;
        
        for(int i=0;i<words.size();++i)
        {
            int wordsmask=0;
            for(int j=0;j<words[i].size();++j)
            {
                wordsmask |= 1 << (words[i][j]-'a');
            }
            
            mask.push_back(wordsmask);
            
            for(int k=0;k<i;++k)
            if(!(mask[k]&mask[i])) 
                ret = max(ret, int(words[k].size()*words[i].size()));
            
        }
        
        
        
        
        
        
        
        return ret;
    }
};