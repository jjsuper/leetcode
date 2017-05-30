class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, maxcnt=0;
        
        for(auto it:nums) {
            if(it) cnt++;
            else {
                maxcnt=max(maxcnt,cnt);
                cnt=0;
            }
        }
        
        return max(cnt,maxcnt);
    }
};