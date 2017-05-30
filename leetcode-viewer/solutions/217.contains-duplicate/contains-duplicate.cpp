class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

    set<int> myset;
//  std::set<int>::iterator it;
    
    for(int i=0;i<nums.size();++i)
    {
        if(myset.find(nums[i])!=myset.end()) return true;
        myset.insert(nums[i]);
        
    }
    
    return 0;
    }
};