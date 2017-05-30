class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size());
    }
private:
    int mergesort(vector<int>& nums, int start, int end) {
        if(start+1>=end) return 0;

        int mid=(start+end)/2;
        int cnt=mergesort(nums, start, mid) + mergesort(nums, mid, end);
        

        for(int i=start, j=mid; i<mid; ++i) {
            while(j<end && nums[i]/2.0 > nums[j]) j++;
            cnt += j-mid;
        }
        
        int idx1=start, idx2=mid;
        
        vector<int> tmp(end-start, 0);
        while(idx1<mid || idx2<end) {
            tmp[idx1-start+idx2-mid]=(idx2==end || (idx1<mid && nums[idx1]<=nums[idx2]))? nums[idx1++]: nums[idx2++];
        }
        
        for(int i=start; i<end; ++i) {
            nums[i]=tmp[i-start];
        }
        
        
        return cnt;
    }
    
};