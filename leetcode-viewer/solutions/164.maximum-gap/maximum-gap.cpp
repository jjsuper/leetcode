class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int maxNum=INT_MIN, minNum=INT_MAX;
        for(int n: nums) {
            maxNum=max(n, maxNum);
            minNum=min(n, minNum);
        }
        
        int gap=ceil((double)(maxNum-minNum)/(nums.size()-1));
        vector<int> bucketMax(nums.size()-1, INT_MIN);
        vector<int> bucketMin(nums.size()-1, INT_MAX);
        for(int n: nums) {
            if(n==maxNum||n==minNum) continue;
            int idx=(n-minNum)/gap;
            bucketMax[idx]=max(bucketMax[idx], n);
            bucketMin[idx]=min(bucketMin[idx], n);
        }
        
        int res=0;
        int prev=minNum;
        for(int i=0; i<bucketMax.size(); ++i) {
            if(bucketMin[i]==INT_MAX) continue;
            res=max(res, bucketMin[i]-prev);
            prev=bucketMax[i];
        }
        res=max(res, maxNum-prev);
        return res;
    }
};