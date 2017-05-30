class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank;
        
        for(int i=0; i<nums.size(); ++i) rank.push_back(i);
        
        
        sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a]>nums[b];});
        
        vector<string> res(nums.size());
        
        if(nums.size()>0) res[rank[0]]="Gold Medal";
        if(nums.size()>1) res[rank[1]]="Silver Medal";
        if(nums.size()>2) res[rank[2]]="Bronze Medal";
        
        for(int i=3; i<nums.size(); ++i) {
            res[rank[i]]=to_string(i+1);
        }
        
        
        return res;
    }
};