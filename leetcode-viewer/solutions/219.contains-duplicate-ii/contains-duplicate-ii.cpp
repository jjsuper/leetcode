class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::map<int, int> mymap;
        std::map<int, int>::iterator it;
        
        
        for(int i=0; i<nums.size(); ++i)
        {
            it=mymap.find(nums[i]);
            if(it!=mymap.end())
            {
                if((i-it->second)<=k)
                {
                    return true;
                }
                
                it->second=i;
            }
            mymap.insert(pair<int, int>(nums[i],i));
            
        }
        
        return false;
    }
};