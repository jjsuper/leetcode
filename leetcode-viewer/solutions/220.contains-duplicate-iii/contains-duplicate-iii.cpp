class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k<1 || t<0) return false;
        unordered_map<long, long> buckets;
        
        for(int i=0; i<nums.size(); ++i) {
            long remap=(long)nums[i]-INT_MIN;
            long idx=remap/((long)t+1);
            if(buckets.count(idx) 
                || (buckets.count(idx-1) && remap-buckets[idx-1]<= t) 
                || (buckets.count(idx+1) && buckets[idx+1]-remap<= t) )
                return true;
            if(buckets.size()>=k) {
                long last=((long)nums[i-k]-INT_MIN)/((long)t+1);
                buckets.erase(last);
            }
            buckets[idx]=remap;
        }
        
        return false;
    }
};