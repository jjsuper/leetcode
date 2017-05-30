class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hash;
        int maxlen=0;
        
        for(auto n : nums) {
            hash[n]++;
        }
        
        for(auto it=hash.begin(); it!=hash.end(); ++it) {
            if(hash.count(it->first-1)) {
                maxlen=max(maxlen, hash[it->first]+hash[it->first-1]);
            }
        }
        
        return maxlen;
    }
};