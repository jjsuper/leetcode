class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> index(3, 0);
        vector<int> num(n, INT_MAX);
        vector<int> primes={2,3,5};
        num[0]=1;
        
        for(int i=1; i<n; ++i)
        {
            for(int j=0; j<3; ++j) num[i]=min(num[i], primes[j]*num[index[j]]);
            for(int j=0; j<3; ++j) if(num[i]==primes[j]*num[index[j]]) index[j]++;
        }
        
        
        
        return num[n-1];
    }
};