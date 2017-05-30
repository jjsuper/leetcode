class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum=0, len=0;
        unordered_map<int, int> hash;
        
        for(int i=0; i<nums.size(); ++i) {
            sum+=nums[i];
            if(sum==k) len=i+1;
            else if(hash.find(sum-k)!=hash.end()) len=max(len, i-hash[sum-k]);
            if(hash.find(sum)==hash.end()) hash[sum]=i;
        }
        
        return len;
        
    }
};