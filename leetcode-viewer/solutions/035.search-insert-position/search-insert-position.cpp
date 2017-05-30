class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left, right, mid;
        left=0;
        right=nums.size()-1;
        mid=(left+right)/2;
        
        while(left<=right)
        {
            if(target==nums[mid]) return mid;
            if(target<nums[mid])
            {
                right=mid-1;
                mid=(left+right)/2;
            }
            else
            {
                left=mid+1;
                mid=(left+right)/2;
            }
        }
        
        
        
        return left;
    }
};