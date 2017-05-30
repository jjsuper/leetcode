class Solution {
public:
    string validIPAddress(string IP) {
        string res[3]={"IPv4", "IPv6", "Neither"};
        stringstream ss(IP);
        string block;
        //IPv4
        if(IP.substr(0,4).find('.')!=string::npos) {
            for(int i=0; i<4; ++i) {
                if(!getline(ss, block, '.') || !isValidIPv4block(block))
                    return res[2];
            }
            return ss.eof()? res[0]: res[2];
        }
        //IPv6
        if(IP.substr(0,5).find(':')!=string::npos) {
            for(int i=0; i<8; ++i) {
                if(!getline(ss, block, ':') || !isValidIPv6block(block))
                    return res[2];
            }
            return ss.eof()? res[1]: res[2];
        }
        
        return res[2];
    }
private:
    bool isValidIPv4block(string block) {
        if(block.size()>3 || block.empty()) return false;
        int num=0;
        for(int i=0; i<block.size(); ++i) {
            if(i==0 && block[i]=='0' && block.size()>1) return false;
            if(!isdigit(block[i])) return false;
            num=num*10+block[i]-'0';
        }
        if(num>255) return false;
        return true;
    }
    
    bool isValidIPv6block(string block) {
        if(block.size()>4 || block.empty()) return false;
        
        for(int i=0; i<block.size(); ++i) {
            if(!isalpha(block[i]) && !isdigit(block[i])) return false;
            if(isalpha(block[i]) && tolower(block[i])>'f') return false; 
        }
        
        return true;
    }
};