class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger>=desiredTotal) return true;
        int sum=(maxChoosableInteger+1)*maxChoosableInteger/2;
        if(sum<desiredTotal) return false;
        
        int used=0;
        return canIWin(maxChoosableInteger, desiredTotal, used);
            
    }
    
private:
    unordered_map<int, bool> hash;
    bool canIWin(int maxChoosableInteger, int desiredTotal, int used) {
        if(desiredTotal<=0) return false;
        if(hash.count(used)) return hash[used];
        
        for(int i=1; i<=maxChoosableInteger; ++i) {
            int n=1<<(i-1);
            if((n&used)==0) {
                used |= n;
                
                if(!canIWin(maxChoosableInteger, desiredTotal-i, used)) {
                    used ^= n;
                    hash[used]=true;
                    return true;
                }
                
                
                used ^= n;
            }
        }
        
        
        hash[used]=false;
        return false;
    }
    
};