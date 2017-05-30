class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=nums[0]+nums[1]+nums[2];
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();++i) {
            int front=i+1;
            int back=nums.size()-1;
            
            while(front<back) {
                int sum=nums[i]+nums[front]+nums[back];
                
                if(abs(target-sum) < abs(res-target)) {
                        res=sum;   
                }
                
                if (sum<target) {
                    front++;
                }
                else if (sum>target) {
                    back--;
                }
                else {
                    return target;
                }
            }
        }
        
        return res;
    }
};