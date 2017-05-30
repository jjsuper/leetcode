class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int, int> hash;
        vector<int> res;
        
        for(int i=0; i<numbers.size(); ++i) {
            if(hash.count(target-numbers[i])) {
                res.push_back(hash[target-numbers[i]]);
                res.push_back(i);
                return res;
            }
            hash[numbers[i]]=i;
        }
        
    }
};