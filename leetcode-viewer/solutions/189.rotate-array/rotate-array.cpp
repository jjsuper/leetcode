class Solution {
public:
    void rotate(int nums[], int n, int k) {
        
        
        int newarray[n];
        
        for(int i=0; i<n; ++i)
        {
            int p=i-k;
            while(p<0)
            {
                p+=n;
            }
            p=p%n;
            
            newarray[i]=nums[p];
        }
        
        for(int i=0; i<n; ++i)
        {
            nums[i] = newarray[i];
        }
        
        
    }
};