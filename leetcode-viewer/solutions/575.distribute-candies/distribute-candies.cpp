class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> hash;
        for(auto n : candies) hash.insert(n);
        return hash.size() >= candies.size()/2 ? candies.size()/2: hash.size();
    }
};