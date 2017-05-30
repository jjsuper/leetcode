class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        vector<long> sums(nums.size()+1, 0);
        
        for(int i=0; i<nums.size(); ++i) {
            sums[i+1]=sums[i]+nums[i];
        }
        
        return mergesort(sums, 0, sums.size(), lower, upper);
    }
private:
    int mergesort(vector<long>& sums, int start, int end, int lower, int upper) {
        if(start+1>=end) return 0;
        //if(start+1==end && sums[start]>=lower && sums[start]<=lower) return 1; 
        
        int mid=(start+end)/2;
        int cnt=mergesort(sums, start, mid, lower, upper)+mergesort(sums, mid, end, lower, upper);
        
        int i=start, j=mid, k=mid;
        
        while(i<mid) {
            while(j<end && sums[j]-sums[i]<lower) j++;
            while(k<end && sums[k]-sums[i]<=upper) k++;
            cnt+= k-j;
            i++;
        }

        
        vector<long> tmp(end-start, 0);
        int idx1=start, idx2=mid;
        
        while(idx1<mid || idx2<end) {
            if(idx2==end || (idx1<mid && sums[idx1]<=sums[idx2])) {
                tmp[idx1-start+idx2-mid]=sums[idx1++];
            }
            else {
                tmp[idx1-start+idx2-mid]=sums[idx2++];
            }
        }
        
        for(int i=start; i<end; ++i) {
            sums[i]=tmp[i-start];
        }
        
        
        return cnt;
    }
};