class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<2) return;
        int n=nums.size();
        
        int mid=findKthelement(nums, n/2);
        
        
        
        #define A(i) nums[(1+2*i)%(n|1)]
        

        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i=0, j=0, k=n-1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
        
    }
private:
    int findKthelement(vector<int>& nums, int k) {
        int left=0, right=nums.size()-1;
        
        while(true) {
            int pos=partition(nums, left, right);
            if(k-1==pos) return nums[pos];
            else if(k-1<pos) right=pos-1;
            else left=pos+1;
        }
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot=nums[left];
        int l=left+1, r=right;
        while(l<=r) {
            if(pivot>nums[l] && pivot<nums[r]) swap(nums[l++], nums[r--]); 
            if(pivot<=nums[l]) l++;
            if(pivot>=nums[r]) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
};