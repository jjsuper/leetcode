class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        
        
        for(int i=0; i<nums.size(); ++i) {
            int target = -nums[i];
            int front = i+1;
            int back = nums.size()-1;
            
            while(front<back) {
                int sum=nums[front]+nums[back];
                if(sum<target) {
                    front++;
                }
                else if(sum>target) {
                    back--;
                }
                else {
                    vector<int> tuple(3,0);
                    tuple[0]=nums[i];
                    tuple[1]=nums[front];
                    tuple[2]=nums[back];
                    res.push_back(tuple);
                    
                    while(front<back&&nums[front]==tuple[1]) front++;
                    while(front<back&&nums[back]==tuple[2]) back--;
                }
            }
            
            while(nums[i]==nums[i+1]&&i+1) i++;
            
        }
        
        return res;
    }
};