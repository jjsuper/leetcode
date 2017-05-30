class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        len=target.size();
        cand=0;
        
        for(auto word : dictionary) {
            if(word.size()==len) {
                int bit=0;
                for(int i=0; i<len; ++i) {
                    if(word[i]!=target[i]) {
                        bit+=1<<i;
                    }
                }
                bits.push_back(bit);
                
                //cout << bit << endl;
                cand |= bit;
            }
        }
        //cout << cand;
        
        dfs(1, 0);
        
        
        //cout << minmask ;
        
        string res;
        for(int i=0, pre=0; i<len; ++i) {
            if(1<<i & minmask) {
                if (i-pre > 0) res = res+to_string(i-pre);
                pre = i+1;
                res = res+target[i];
            }
            else if(i==len-1){
                res = res+to_string(len-pre);
            }
        }
        
        return res;
    }
private:
    int minlen=INT_MAX, minmask;
    int len, cand=0;
    vector<int> bits;
    
    void dfs(int pos, int mask) {
        bool match=1;
        int masklen=getLen(mask);
        if(masklen>=minlen) return;
        
        //cout << "pos" << pos << " mask" << mask << endl;
        
        for(auto bit : bits) {
            if((bit&mask)==0) {
                match=0;
                break;
            }
        }
        
        
        //cout << match << endl;
        
        if(match) {
            if(masklen<minlen) {
                minlen=masklen;
                minmask=mask;
            }
        }
        else {
            for(int b=pos; b<(1<<len); b<<=1) 
                if(cand & b) dfs(b<<1, mask+b);
        }
    }
    
    int getLen(int mask) {
        int cnt=len;
        for(int i=3; i<(1<<len); i<<=1) {
            if((i & mask)==0) cnt--;
        }
        return cnt;
    }
    
    
};