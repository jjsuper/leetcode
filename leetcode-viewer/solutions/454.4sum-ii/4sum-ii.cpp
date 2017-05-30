class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> AB=fillmap(A, B);
        map<int, int> CD=fillmap(C, D);
        int cnt=0;
        
        for(auto it=AB.begin(); it!=AB.end(); ++it) {
            if(CD.find(-it->first)!=CD.end())
                cnt+= it->second * CD[-it->first];
        }
        
        
        
        return cnt;
    }
private:
    map<int, int> fillmap(vector<int>& A, vector<int>& B) {
        map<int, int> m;
        for(int i=0; i<A.size(); ++i) 
            for(int j=0; j<B.size(); ++j)
                m[A[i]+B[j]]++;
        return m;
    }
};