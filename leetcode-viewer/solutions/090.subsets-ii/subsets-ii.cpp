class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res={{}};
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); ) {
            int cnt=0;
            while(cnt+i<nums.size() && nums[cnt+i]==nums[i]) cnt++;
            int preNum=res.size();
            for(int j=0; j<preNum; ++j) {
                vector<int> instance=res[j];
                for(int k=0; k<cnt; ++k) {
                    instance.push_back(nums[i]);
                    res.push_back(instance);
                }
            }
            i+=cnt;
        }
        
        return res;
    }
};