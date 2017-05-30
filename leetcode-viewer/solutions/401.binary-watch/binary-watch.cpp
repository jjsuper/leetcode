class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        int minute;
        
        for(int i=0; i<12; ++i) {
            minute=num-getNumofOne(i);
            if(minute<0) continue;
            for(int j=0; j<60; ++j) {
                if(minute==getNumofOne(j)) {
                    string s=to_string(i);
                    s+=':';
                    if(j<10) s+='0';
                    s+=to_string(j);
                    res.push_back(s);
                }
            }
        }
        return res;
        
    }
private:
    int getNumofOne(int x) {
        int num=0;
        while(x) { x=x&(x-1); num++;}
        return num;
    }
};