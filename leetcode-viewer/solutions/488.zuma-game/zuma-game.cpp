class Solution {
public:
    int findMinStep(string board, string hand) {
        maxstep=6;
        sort(hand.begin(), hand.end());
        int minstep=helper(board, hand);
        return minstep>hand.size()? -1: minstep;
    }
private:
    int maxstep;
    int helper(string b, string h) {
        if(b.empty()) return 0;
        if(h.empty()) return maxstep;
        int res=maxstep;
        
        for(int i=0; i<h.size(); ++i) {
            int j=0;
            int n=b.size();
            while(j<n) {
                int k=b.find(h[i], j);
                if(k==string::npos) break;
                if(k<n-1&&b[k]==b[k+1]) {
                    string nextb=shrink(b.substr(0,k)+h[i]+b.substr(k));
                    if(nextb.empty()) return 1;
                    string nexth=h;
                    nexth.erase(i,1);
                    res=min(res, helper(nextb, nexth)+1);
                    k++;
                }
                else if(i<h.size()-1 && h[i]==h[i+1]) {
                    string nextb=shrink(b.substr(0,k)+h[i]+h[i]+b.substr(k));
                    if(nextb.empty()) return 2;
                    string nexth=h;
                    nexth.erase(i,2);
                    res=min(res, helper(nextb, nexth)+2);
                }
                j=k+1;
            }
        }
        return res;
    }

    string shrink(string s) {/*
        bool done=0;
        
        while(!done) {
            done=1;
            for(int i=0; i<s.size()-2; ++i) {
                if(s[i]==s[i+1]&&s[i]==s[i+2]) {
                    int j=i+3;
                    while(s[i]==s[j]&&j<s.size()) j++;
                    s=s.substr(0,i)+s.substr(j);
                    done=0;
                }
            }    
        }
        return s;*/
         while(s.size() > 0) {
            int start = 0;
            bool done = true;
            for (int i = 0; i <= s.size(); i++) {
                if (i == s.size() || s[i] != s[start]) {
                    if (i - start >= 3) {
                        s = s.substr(0, start) + s.substr(i);
                        done = false;
                        break;
                    }
                    start = i;
                }
            }
            if (done) break;
        }
        return s;
    }
    
};