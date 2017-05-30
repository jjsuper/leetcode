class NumArray {
public:
    NumArray(vector<int> nums) {
        n=nums.size();
        BIT.assign(n+1, 0);
        num.assign(n, 0);
        for(int i=0; i<n; ++i)
            update(i, nums[i]);
    }
    
    void update(int i, int val) {
        int diff=val-num[i];
        num[i]=val;
        i++;
        while(i<=n) {
            BIT[i]+=diff;
            i+=(i&-i);
        }
    }
    
    int sumRange(int i, int j) {
        return read(j)-read(i-1);
    }
    
    int read(int i) {
        i++;
        int sum=0;
        while(i>0) {
            sum+=BIT[i];
            i-=(i&-i);
        }
        return sum;
    }
    
private:
    vector<int> BIT;
    int n;
    vector<int> num;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */