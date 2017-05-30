class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        dfs(s, 0, 0, "", result);
        return result;
    }
private:
    void dfs(string s, int start, int step, string ip, vector<string> &result)
    {
        if(start==s.size() && step==4) 
        {
            ip.resize(ip.size()-1);
            result.push_back(ip);
            return;
        }
        
        if(s.size()-start>(4-step)*3) return;
        if(s.size()-start<(4-step)*1) return;
        
        int num=0;
        for(int i=start; i<start+3; ++i)
        {
            num = num*10 + (s[i]-'0');
            
            if(num<256)
            {
                ip+=s[i];
                dfs(s, i+1, step+1, ip+'.', result);
            }
            if(num==0) break;
        }
        return;
    }
};