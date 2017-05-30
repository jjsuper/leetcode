class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0, right=nums.size()-1;
        
        while(true)
        {
            int pos=partition(nums, left, right);
            if(pos==k-1) return nums[pos];
            else if (pos>k-1) right=pos-1;
            else left=pos+1;
            
        }
        
    }
    
    int partition(vector<int>& nums, int left, int right)
    {
        int pivot=nums[left];
        int l=left+1;
        int r=right;
        
        while(l<=r)
        {
            if(pivot<nums[r] && pivot>nums[l]) swap(nums[l++], nums[r--]);
            if(pivot<=nums[l]) l++;
            if(pivot>=nums[r]) r--;
            
        }
        swap(nums[left], nums[r]);
        
        return r;
    }
    
};