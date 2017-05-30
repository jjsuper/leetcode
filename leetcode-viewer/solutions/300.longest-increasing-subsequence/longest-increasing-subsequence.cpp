class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subseq;
        for(int i=0; i<nums.size(); ++i) {
            insert(subseq, nums[i]);
        }
        return subseq.size();
    }
    
    void insert(vector<int>& sub, int num) {
        if(sub.empty()) {
            sub.push_back(num);
            return;
        }
        if(num>sub.back()) {
            sub.push_back(num);
            return;
        }
        
        int start=0, end=sub.size()-1;
        while(start<end) {
            int mid=(start+end)/2;
            if(sub[mid]==num) return;
            else if(sub[mid]<num) start=mid+1;
            else end=mid;
        }
        
        sub[end]=num;
    }
    
};