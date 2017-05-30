class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first<b.first || (a.first==b.first && a.second>b.second);
        });
        
        vector<int> h;
        
        for(auto e : envelopes) {
            insert(h, e.second);
        }
        
        return h.size();
    }
    
private:
    void insert(vector<int>& nums, int target) {
        //cout << target << endl;
        if(nums.empty()) nums.push_back(target);
        if(nums.back() < target) nums.push_back(target);
        
        int left=0, right=nums.size()-1;
        while(left<=right) {
            int mid=(left+right)/2;
            if(nums[mid] == target) {
                return;
            }
            else if(nums[mid] < target) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        
        nums[left]=target;
        return;
    }
};