class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res=0;
        
        for(int i=0; i<nums.size(); ++i) {
            int cur = nums[i];
            int cnt = 0;
            nums[i] = -1;
            while(cur!=-1) {
                int tmp = cur;
                cur = nums[cur];
                nums[tmp] = -1;
                cnt ++;
            }
            res=max(res, cnt);
        }
        
        return res;
    }
};