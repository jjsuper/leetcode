class PhoneDirectory {
private:
    vector<bool> used;
    queue<int> freelist;
    int maxNum;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        maxNum=maxNumbers;
        used.assign(maxNum, 0);
        for(int i=0; i<maxNum; ++i) freelist.push(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(!freelist.empty()) {
            int res=freelist.front();
            freelist.pop();
            used[res]=1;
            return res;
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(number>=maxNum) return false;
        return !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number>=maxNum) return;
        if(used[number]==1) freelist.push(number);
        used[number]=0;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */