class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size(), 0);
        if(nums.empty()) return res;
        int i=0, j=nums.size()-1;
        int index;
        if(a>=0) index=nums.size()-1;
        else index=0;
        
        while(i<=j) {
            if(a>=0) {
                int v1=a*nums[i]*nums[i]+b*nums[i]+c;
                int v2=a*nums[j]*nums[j]+b*nums[j]+c;
                if(v1>=v2) {
                    res[index--]=v1;
                    i++;
                }
                else {
                    res[index--]=v2;
                    j--;
                }
            }
            else {
                int v1=a*nums[i]*nums[i]+b*nums[i]+c;
                int v2=a*nums[j]*nums[j]+b*nums[j]+c;
                if(v1<=v2) {
                    res[index++]=v1;
                    i++;
                }
                else {
                    res[index++]=v2;
                    j--;
                }            
            }
        }
        
        
        return res;
    }
};