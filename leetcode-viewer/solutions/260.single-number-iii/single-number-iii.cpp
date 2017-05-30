class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR=0;
        vector<int> res;
        
        for(int i=0;i<nums.size();++i)
            XOR = XOR^nums[i];
        
        int lastBit= (XOR&(XOR-1))^XOR;
        int intA=0, intB=0;
        
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]&lastBit) intA^=nums[i];
            else intB^=nums[i];
        }
        
        res.push_back(intA);
        res.push_back(intB);
        return res;
        
    }
};