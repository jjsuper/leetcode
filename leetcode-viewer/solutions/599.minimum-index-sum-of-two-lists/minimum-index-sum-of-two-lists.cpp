class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        int sum=INT_MAX;
        unordered_map<string, int> hash;
        
        for(int i=0; i<list1.size(); ++i) {
            hash[list1[i]]=i;
        }
        
        for(int i=0; i<list2.size(); ++i) {
            if(hash.count(list2[i])) {
                int cur = hash[list2[i]]+i;
                if(cur<sum) {
                    res.clear();
                    res.push_back(list2[i]);
                    sum=cur;
                }
                else if(cur==sum) {
                    res.push_back(list2[i]);
                }
            }
        }
        
        
        return res;
    }
};