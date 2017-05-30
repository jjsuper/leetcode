class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int res=0;
        
        int cnt=0;
        while(cnt!=nums.size()) {
            int One=0;

            cnt=0;
            for(int i=0; i<nums.size(); ++i) {
                if(!nums[i]) cnt++;
                if(nums[i]%2) One++;
                nums[i] = nums[i] >>1;
            }
            
            res+=One*(nums.size()-One);
            
        }
        
    
        
        return res;
        /*
        int size = nums.size();
        if(size < 2) return 0;
        int ans = 0;
        int *zeroOne = new int[2];
        while(true)
        {
            int zeroCount = 0;
            zeroOne[0] = 0;
            zeroOne[1] = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == 0) zeroCount++;
                zeroOne[nums[i] % 2]++;
                nums[i] = nums[i] >> 1;
            }
            ans += zeroOne[0] * zeroOne[1];
            if(zeroCount == nums.size()) return ans;
        }*/
    }
};