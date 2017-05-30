class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        
        for(int i=0; i<words.size(); ) {
            string cur;
            int j, len;
            for(j=i, len=0; j<words.size() && len+words[j].size()+j-i<=maxWidth; ++j) {
                len+=words[j].size();
            }
            int spaces=maxWidth-len;
            int num=j-i;
            //cout << spaces << " " << num << endl;
            int k;
            for(k=i; k<j-1; ++k) {
                cur+=words[k];
                
                if(j==words.size()) {
                    cur+=' ';
                }
                else {
                    int n=spaces/(num-1)+(k<((spaces%(num-1))+i));
                    cout << n <<endl;
                    cur+=string(n, ' ');
                }
            }
            
            cur+=words[k];
            
            cur+=string(maxWidth-cur.size(), ' ');
            
            
            res.push_back(cur);
            i=j;
            
        }
        
        
        return res;
    }
};