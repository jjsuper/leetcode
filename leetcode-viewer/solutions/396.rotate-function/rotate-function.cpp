class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sumRotate=0;
        int sum=0;
        
        for(int i=0; i<A.size(); ++i) {
            sumRotate+=i*A[i];
            sum+=A[i];
        }
        
        int result=sumRotate;
        for(int i=A.size()-1; i>0; i--) {
            sumRotate=sumRotate+sum-A[i]*A.size();
            result=max(result, sumRotate);
        }
        
        return result;
    }
};