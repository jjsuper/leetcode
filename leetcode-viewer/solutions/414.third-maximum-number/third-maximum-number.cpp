class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> v(nums.begin(), nums.end());
        
        int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN;
        for(auto it: v) {
            if(it>max1) {
                max3=max2;
                max2=max1;
                max1=it;
            }
            else if(it<max1 && it>max2) {
                max3=max2;
                max2=it;
            }
            else if(it<max2 && it>max3) {
                max3=it;
            }
        }
        
        return v.size()<3? max1: max3;
    }
};