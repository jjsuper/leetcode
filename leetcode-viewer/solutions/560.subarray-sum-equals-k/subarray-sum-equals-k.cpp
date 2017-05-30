class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int res=0;
        int sum=0;
        hash[sum]=1;
        for(auto n : nums) {
            sum+=n;
            
            if(hash.count(sum-k)>0) {
                res+=hash[sum-k];
            }
            hash[sum]++;
        }
        return res;
    }
};