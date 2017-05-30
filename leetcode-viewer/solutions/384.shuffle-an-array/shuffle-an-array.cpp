class Solution {
private:
    vector<int> _num, arr;
public:
    Solution(vector<int> nums) {
       // srand(time(NULL));
        for(int i=0; i<nums.size(); ++i) {
            _num.push_back(nums[i]);
            arr.push_back(nums[i]);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        for(int i=0; i<_num.size(); ++i) {
            arr[i] = _num[i];
        }
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=1; i<arr.size(); ++i) {
            swap(arr[i], arr[rand()%(i+1)]);   
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */