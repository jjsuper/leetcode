class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0; i<nums.size(); ++i){
            if(!nums[i]) nums[i]=-1;   
        }
        
        unordered_map<int, int> hash;
        int sum=0, len=0;
        hash[0]=-1;
        
        for(int i=0; i<nums.size(); ++i) {
            cout << nums[i];
            sum+=nums[i];
            if(hash.find(sum)!=hash.end()) {
                len=max(len, i-hash[sum]);
            }
            else {
                hash[sum]=i;
            }
        }
        
        return len;
    }
};