class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> mystack;
        for(int i=0; i<2*nums.size(); ++i) {
            int num=nums[i%nums.size()];
            while(!mystack.empty() && num>nums[mystack.top()]) {
                res[mystack.top()] = num;
                mystack.pop();
            }
            if(i<nums.size()) mystack.push(i); 
        }
        return res;
    }
};