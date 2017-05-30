class Solution {
public:
    int nextGreaterElement(int n) {
        if(n<0 || n>INT_MAX) return -1; 
        vector<int> num;
        int pivot=INT_MAX;
        
        while(n>0) {
            int rem=n%10;
            n/=10;
            if(!num.empty() && rem<num.back()) {
                pivot=rem;
                break;
            }
            num.push_back(rem);
        }
        
        
        
        if(pivot==INT_MAX) return -1;
        
        long res=n*10;
        
        for(int i=0; i<num.size(); ++i) {
            if(num[i]>pivot) {
                res+=num[i];
                num[i]=pivot;
                break;
            }
        }
        
        for(int i=0; i<num.size(); ++i) {
            res=res*10+num[i];
        }
        
        
        return res>INT_MAX? -1 :res;
    }
};