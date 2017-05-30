class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> s(nums.begin(), nums.begin()+k);
        auto mid=next(s.begin(), k/2);
        res.push_back(*mid/2.0 + *prev(mid, 1-k%2)/2.0);
        
        for(int i=k; i<nums.size(); ++i) {
            s.insert(nums[i]);
            if(nums[i]<*mid) mid--;
            if(nums[i-k]<=*mid) mid++;
            s.erase(s.find(nums[i-k]));
            res.push_back(*mid/2.0 + *prev(mid, 1-k%2)/2.0);
        }
        
        return res;
    }
};