class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(),0);
        vector<int> num(n, INT_MAX);
        
        num[0]=1;
        
        for(int i=1; i<n; ++i)
        {
            for(int j=0; j<primes.size(); ++j) num[i]=min(num[i], primes[j]*num[index[j]]);
            for(int j=0; j<primes.size(); ++j) if(num[i]==primes[j]*num[index[j]]) index[j]++;
        }
        
        
        
        
        return num[n-1];
    }
};