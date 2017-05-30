class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> numset(nums.begin(), nums.end());
        int res=1;
        for(auto n:nums) {
            if(numset.find(n)==numset.end()) continue;
            numset.erase(n);
            int prev=n-1, next=n+1;
            while(numset.find(prev)!=numset.end()) numset.erase(prev--);
            while(numset.find(next)!=numset.end()) numset.erase(next++);
            res=max(res, next-prev-1);
        }
        return res;
    }
};