class NumArray {
public:
    NumArray(vector<int> &nums) {
        int pre=0;
        for(int i=0;i<nums.size();++i)
        {
            sum.push_back(pre+nums[i]);
            pre=sum.back();
        }
    }

    int sumRange(int i, int j) {
        if(i==0) return sum[j];
        return sum[j]-sum[i-1];
    }
    
private:
    vector<int> sum;

};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);