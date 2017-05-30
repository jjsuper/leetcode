class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {  //m'0' n'1'
        vector<vector<int>> cnt(m+1, vector<int>(n+1, 0));
        
        for(string s:strs) {
            int numOnes=0, numZeros=0;
            for(char c:s) {
                if(c=='1') numOnes++;
                else numZeros++;
            }
            
            for(int i=m; i>=numZeros; --i) 
                for(int j=n; j>=numOnes; --j) {
                    cnt[i][j]=max(cnt[i][j], cnt[i-numZeros][j-numOnes]+1);
                }
        }
        
        return cnt[m][n];
    }
};