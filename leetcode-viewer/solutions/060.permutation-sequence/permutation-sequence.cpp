class Solution {
public:
    string getPermutation(int n, int k) {
        string res="";
        vector<int> num(n, 0);
        int factorial=1;
        
        for(int i=1; i<=n; ++i) {
            num[i-1]=i;
            factorial*=i;
        }
        
        k--;
        
        for(int i=0; i<n; ++i) {
            factorial/=n-i;
            int index=k/factorial;
            res+=to_string(num[index]);
            num.erase(num.begin()+index);
            k-=index*factorial;
        }
        
        
        return res;
        
    }
};