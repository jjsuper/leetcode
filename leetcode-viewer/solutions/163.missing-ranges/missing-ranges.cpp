class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        long prev=(long)lower;
        vector<string> res;
        
        for(int i=0; i<=nums.size(); ++i) {
            long value=((i==nums.size())? (long)upper+1: nums[i]);
            if(value>prev) {
                if(value-prev>1) {
                    string cur=to_string(prev)+"->"+to_string(value-1);
                    res.push_back(cur);
                }
                else {
                    res.push_back(to_string(prev));
                }
            }
            prev=value+1;
        }

        
        return res;
        
    }
   
};