class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        data.clear();
        quesize=size;
    }
    
    double next(int val) {
        double res=0;
        
        data.push_back(val);
        if(data.size()>quesize) data.erase(data.begin());
        
        for(int i=0; i<data.size(); ++i) res+=data[i];
        
        return res/data.size();
    }
private:
    vector<int> data;
    int quesize;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */