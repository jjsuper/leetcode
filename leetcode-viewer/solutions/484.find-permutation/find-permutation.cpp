class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res(s.size()+1, 0);
        
        for(int i=0; i<res.size(); ++i)
            res[i]=i+1;
        
        for(int i=0; i<s.size(); ++i) {
            if(s[i]=='D') {
                int j=i;
                while(s[j]=='D'&&j<s.size()) j++;
                int k=i;
                i=j;
                while(k<j) {swap(res[k++], res[j--]);}
            }
        }
        return res;        
    }
};