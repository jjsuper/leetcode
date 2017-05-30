class MinStack {
public:
    void push(int x) {
        data.push_back(x);
        if (minData.empty()) minData.push_back(x);
    else minData.push_back(min(minData.back(),x));
    }

    void pop() {
        data.pop_back();
        minData.pop_back();
    }

    int top() {
        return data.back();
    }

    int getMin() {
        return minData.back();
    }
    
    
vector<int> data;
vector<int> minData;

};