class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        res[0]=lower(nums, target);
        if(res[0]==-1) return res; 
        res[1]=upper(nums, target);
        return res;
    }
private:
    int lower(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left<right) {
            int mid=(left+right)/2;
            if(nums[mid]<target) {
                left=mid+1;
            }
            else 
                right=mid;
        }
        //cout << left <<endl;
        return nums[left]==target? left: -1;
    }
    int upper(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left<right) {
            int mid=(left+right)/2+1;
            if(nums[mid]>target) {
                right=mid-1;
            }
            else 
                left=mid;
        }
        //cout << right << endl;
        return nums[right]==target? right: -1;
        //return right;
    }
};