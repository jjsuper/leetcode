class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size();
        vector<int> sum(len + 1, 0);
        
        for (int i=0; i<len; ++i) {
            sum[i+1]=sum[i]+machines[i];
        }
        
        if(sum[len]%len) return -1;
        
        int avg=sum[len]/len;
        int res=0;
        
        for(int i=0; i<len; ++i) {
            int L=avg*i-sum[i];
            int R=avg*(len-i-1)-(sum[len]-sum[i+1]);
            if(L>0 && R>0) 
                res=max(res, L+R);
            else 
                res=max(res, max(abs(L), abs(R)));
        }
        
        
        return res;
    }
};